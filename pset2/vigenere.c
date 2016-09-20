#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

int isItAlpha(string n){
    int len = strlen(n);
    int checker = 0;
    for (int i=0;i<len;i++){
       if (isalpha(n[i])){
        checker += 0;
       }
       else checker +=1;
    }
    if (checker>0)
    return 1;
    else return 0;
}
char charToInt(char ch){
    char chInt = toupper(ch);
    chInt -= 65; 
    return chInt;
}

char* keysArray(string key, string text){
    char* keys = (char*) malloc(sizeof(char));
           int i = 0;
           int j =0;
           int lenText = strlen(text);
           while (i<lenText){
               if (j>=strlen(key)){
               j=0;
               keys[i]=key[j];
               }
               else
               keys[i]=key[j];
               j++;
               i++;
           }
           for (i=0; i < strlen(keys);i++){
           }
           return keys;
}
char charEncrypt(char ch, char step){
    char crypt;
    if (isalpha(ch)){
        if (isupper(ch)){
            crypt = ((ch+step)-65)%26+65;
    }
        else{
            crypt = ((ch+step)-97)%26+97;
    }
    }   
    else{
        crypt = ch;
    }
    return crypt;
}
int main(int argc, string argv[]){
    if (argc!=2 || isItAlpha(argv[1])) {
       printf ("Usage: ./caesar k\n");
       return 1;
   }
       else{
           printf("plaintext: ");
            string text = GetString();
            printf("ciphertext: ");
            char* keyArr = keysArray(argv[1], text);
            int j = 0;
           for (int i = 0; i < strlen(text); i++){
            printf("%c", charEncrypt(text[i], charToInt(keyArr[j])));
            if (isalpha(text[i])){
                j++;
            }
           }
           printf("\n");
           return 0;
       }
   }