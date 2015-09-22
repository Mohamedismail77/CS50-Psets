
/* 
**************************
** Welcome back to CS50
** Mohamed Ismail
** Problem set2
** INITIaLS
**************************
*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string Name = GetString();
    char First_Char = Name[0];
    char Next_Char;
    // Convert first character to upper case & print it
    First_Char = toupper(First_Char);
    printf("%c",First_Char);
    
    // Get the next cahracter after the space & convert it & print it out
    for(int i = 0; i < strlen(Name); i++)
    {
        if (Name[i] == ' ' )
        {
            Next_Char = Name[i + 1];
            Next_Char = toupper(Next_Char);
            printf("%c",Next_Char);
        }
    }

    printf("\n");
}
