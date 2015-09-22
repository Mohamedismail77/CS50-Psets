/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    // TODO
    // open the memory card
    FILE* inptr = fopen("card.raw","r");
    
    BYTE data[512];
    int index = 0;
    fread(&data , 1 , 512,inptr);
    while(!feof(inptr))
    {
        
        //find the first of jpg file
        if((data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff) && (data[3] == 0xe0 || data[3] == 0xe1))
        {
            //export the file in ###.jpg
            sprintf(argv[0],"%03d.jpg",index);
            FILE* image = fopen(argv[0],"w");
            //start all over again until reach to the end of file and start of new
            do
             {   
                //save this in buffer
                fwrite(&data , 1 , 512 ,image);
                fread(&data , 1 , 512,inptr);
                if(feof(inptr))
                {
                    break;
                }
             }while(!((data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff) && (data[3] == 0xe0 || data[3] == 0xe1)));
            
            index++;
            fclose(image);
        }
        else
        {
            fread(&data , 1 , 512,inptr);
        }
     }

    //close the file
    fclose(inptr);
}
