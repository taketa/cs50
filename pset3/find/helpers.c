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
   int low=0;
   int high=n;
   int middle;
   
       while(low<=high){
           middle = (low + high) / 2;
           if (value == values[middle]){
               return true;
           }
            else if (value < values[middle]){
                high = middle - 1;
           }
            else {
                low = middle + 1;
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
   int rem;
   for (int j=1; j<n; j++) {
       for (int i=0; i<n-1; i++) {
           if (values[i]>values[i+1]){
               rem = values[i];
               values[i]=values[i+1];
               values[i+1] = rem;
           }
       }
   }
   return;
} 