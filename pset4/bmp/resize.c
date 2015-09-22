/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "bmp.h"
void writetofile(RGBTRIPLE triple[],long width,int number);
FILE* outptr;
int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember filenames
    int number = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    while( number < 0 || number > 100)
    {
        printf("numer must be in range [0,100]:");
        number = GetInt();
        printf("\n");
    }
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    BITMAPFILEHEADER bfo;
    BITMAPINFOHEADER bio;
    bio = bi;
    bfo = bf;
    bio.biWidth = number * bi.biWidth;
    bio.biHeight = number * bi.biHeight;
    int paddingo =  (4 - (bio.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bio.biSizeImage = abs(bio.biHeight) * ((bio.biWidth*3)+paddingo);
    bfo.bfSize = bio.biSizeImage + 54;
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
                
                RGBTRIPLE triple[bi.biWidth];
		        for (int j = 0; j < (bi.biWidth); j++)
		        {
		            // read RGB triple from infile
		            fread(&triple[j], sizeof(RGBTRIPLE), 1, inptr);
		        }
		        
               
		        for(int f = 0; f < number; f++)
		        {
		            for(int j = 0; j < bi.biWidth; j++)
                    {
                    	for(int k = 0; k < number; k++)
                        {
			                // write RGB triple to outfile
		                    fwrite(&triple[j], sizeof(RGBTRIPLE), 1, outptr);		
                        }

                    }
                    for (int k = 0; k < paddingo; k++)
                    {
                        fputc(0x00, outptr);
                    }
                    
                }
                // skip over padding, if any
                fseek(inptr, padding, SEEK_CUR); 
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}


