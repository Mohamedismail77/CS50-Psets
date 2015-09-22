/* Welcome back to CS50
** Mohamed Ismail
** Problem set2
** Hello Ceasar
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    if (argc < 2)
    {
        printf("Enter the plan txt");
        return 1 ;
    }
    int Key =atoi(argv[1]); 
    string plan = GetString(); 
    for(int j = 0; j < strlen(plan);j++)
    {
        if (isalpha(plan[j]))
        {
            if (isupper(plan[j]))
            {
                int plant = plan[j] - 65;
                int Cypt = (plant + Key) % 26;
                plant = Cypt + 65;
                printf("%c",(char) plant);
            }
            if (islower(plan[j]))
            {
                int plant = plan[j] - 97;
                int Cypt = (plant + Key) % 26;
                plant = Cypt + 97;
                printf("%c",(char) plant);
            }
        }
        else
        {
            printf("%c",plan[j]);
        }
    }
    printf("\n");
}
