#include <stdio.h>
#include <cs50.h>
int main(void){
    printf("minutes: ");
    int minutes = get_int();
    int bottles = 12 * minutes;
    printf("bottles: %i \n", bottles);
    return 0;
}