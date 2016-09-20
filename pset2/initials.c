#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
int main(){
    string name = GetString();
    if (((char)name[0] >=65 && (char)name[0] <= 90) || ((char)name[0] >=97 && (char)name[0] <= 122))
    printf("%c", toupper((char)name[0]));
    for (int i = 0; i < strlen(name); i++){
        if ((char)name[i] == 32){
            if (((char)name[i+1] >=65 && (char)name[i+1] <= 90) || ((char)name[i+1] >=97 && (char)name[i+1] <= 122))
            printf("%c",toupper((char)name[i+1]));
        }
    }
    printf("\n");
    return 0;
}