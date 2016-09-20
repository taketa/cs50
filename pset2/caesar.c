#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[]){
    if (argc!=2) {
       printf ("Usage: ./caesar k\n");
       return 1;
   }
   else{
       int key = atoi(argv[1]);
   printf("plaintext: ");
   string text = GetString();
   printf("ciphertext: ");

      int len = strlen(text);
       for (int i = 0; i <= len-1; i++){
           if (text[i]>=97 && text[i]<=122){
               char crypt = ((text[i]+key)-97)%26+97;
               printf("%c", crypt);
           }
           else if(text[i]>=65 && text[i]<=90){
               char crypt = ((text[i]+key)-65)%26+65;
               printf("%c", crypt);
           }
           else {
               printf("%c", text[i]);
           }
       }
       printf("\n");
       return 0;

   }
   

}