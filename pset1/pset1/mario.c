#include <stdio.h>
#include <cs50.h>

void spacesPaste(int i){
    while (i>0){
        printf(" ");
        i--;
    }
}
void blocksPaste(int i){
    while (i>0){
        printf("#");
        i--;
    }
}

int main(void){
    int height = -1;
    while (height<0 || height>23){
        printf("height: ");
        height = get_int();
    }
    int blocks = 1;
    int rowQuantity = height;
    while (height>0){
        int spacesQuantity = rowQuantity - blocks;
        spacesPaste(spacesQuantity); 
        blocksPaste(blocks);
        printf("  ");
        blocksPaste(blocks);
        blocks++;
        height--;
        printf("\n");
    }
}