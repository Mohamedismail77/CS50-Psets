/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <cs50.h>
#include "dictionary.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


typedef struct node{
    
    char Word[LENGTH+1];
    struct node* Next;    

}
node;

node* hashtable[26];
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    if((strlen(word) > 0) && (strlen(word) < 46))
    {
        char Word[strlen(word)];
        for(int i = 0 ; i < strlen(word)+1; i++)
        {
           if(isalpha(word[i]))
           {
                Word[i] = tolower(word[i]);
           }
           else
           {
                Word[i] = tolower(word[i]);
           }
        }
        int hashing_index = Word[0] - 'a';
        node* cursor = hashtable[hashing_index];
        while(cursor != NULL)
        {
            if(strcmp(Word,cursor->Word) == 0)
            {
                return true;
            }
            else
            {
                cursor = cursor->Next;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE* inptr = fopen(dictionary,"r");
    int hashing_index;
    if(inptr != NULL)
    {
        
        while(!feof(inptr))
        {
            node* new_node = malloc(sizeof(node));
            fscanf(inptr,"%s",new_node->Word);
            if(isalpha(new_node->Word[0]))
            {
              hashing_index = new_node->Word[0] - 'a';
              new_node->Next = hashtable[hashing_index];
              hashtable[hashing_index] = new_node;
            }
            
        }
        return true;
     }
     else
     {
        return false;
     }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
   int number = 0;
   for(int i =0; i < 26; i++)
   {
        node* cursor = hashtable[i];
        while(cursor != NULL)
        {
            number++;
            cursor = cursor->Next;
        }
   }
   
   return number;
    
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
   for(int i =0; i <26; i++)
   {
        node* cursor = hashtable[i];
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->Next;
            free(temp);
        }
   }
   return true;

   
   
   
}
