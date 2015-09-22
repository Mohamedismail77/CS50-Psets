/* 
**************************
** Welcome back to CS50
** Mohamed Ismail
** Problem set2
** Hello vigenere
**************************
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // handles lack of argv[1] 
    if (argc < 2)
    {
        printf("print the key");
        return 1 ;
    }
    // handles argc > 2
    if (argc > 2)
    {
        printf("delet the other arguments");
        return 1 ;
    } 
    string Key = argv[1];
    // Check for alpha input
    for(int n = 0; n < strlen(Key); n++)
    {
        if (isalpha(Key[n]))
        {}
        else
        {
            printf("enter valid key:");
            return 1;
        }
    }
    // get plan txt
    string plan = GetString();
    int KIN;
    int key;
    int k = 0;
    // start cypher
    for(int j = 0; j < strlen(plan); j++)
    {         
        if (isalpha(plan[j]))
        {       
          
            if (isupper(plan[j]))
            {
                KIN = k % strlen(Key);   
                if (isupper(Key[KIN]))
                {
                    key = Key[KIN] - 65;
                }
                if (islower(Key[KIN]))
                {
                    key = Key[KIN] - 97;
                }
                int plant = plan[j] - 65;
                int Cypt = (plant + key) % 26;
                plant = Cypt + 65;
                plan[j] = (char) plant;
            }
            if (islower(plan[j]))
            {
                KIN = k % strlen(Key);   
                if (isupper(Key[KIN]))
                {
                    key = Key[KIN] - 65;
                }
                if (islower(Key[KIN]))
                {
                    key = Key[KIN] - 97;
                }
                int plant = plan[j] - 97;
                int Cypt = (plant + key) % 26;
                plant = Cypt + 97;
                plan[j] = (char) plant;
                }
            k++; 
        }    
     }
    printf("%s",plan);
    printf("\n");  
} 
