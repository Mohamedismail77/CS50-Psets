/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int start = 0;
    int end = n-1;
    while (end >= start)
    {
        int midle = (end + start)/2;
        if(values[midle] == value)
        {
            return true;
            break;
        }
        else if (values[midle] > value)
        {
            end = midle - 1;
        }
        else
        {
            start = midle + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
        int s;
     for (int i = 0; i < n ; i++)
    {
        // combare element witheach element
        for (int j = i+1; j < n; j++)
        {
            //put the element in its place
            if (values[j] < values[i])
            {   
                s = values[i];
                values[i] = values[j];
                values[j] = s;
            }
        }
    } 
    return;
}
