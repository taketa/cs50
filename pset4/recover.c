/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>


int main(int argc, char* argv[])
{
   if (argc !=2){
      fprintf(stderr, "Usage: ./recover card.raw \n");
      return 1;
   }
   FILE* file = fopen(argv[1], "r");
   if (file == NULL)
   {
       return 1;
   }
   uint8_t bytes[512];
   char title[8];
   FILE* fileToWrite = NULL;
   int titleNum = 0;
   while (fread(bytes, sizeof(bytes), 1, file)){
      
      if (bytes[0]==0xff && bytes[1]==0xd8 && bytes[2]==0xff && (bytes[3]==0xe0 || bytes[3]==0xe1)) {
         if (fileToWrite != NULL){
            fclose(fileToWrite);
         }
         sprintf(title, "%03d.jpg", titleNum);
         fileToWrite = fopen(title, "w");
         titleNum++;
      }
      if (fileToWrite != NULL){
         fwrite(bytes, sizeof(bytes), 1, fileToWrite);
      }
   }
   if (fileToWrite != NULL){
      fclose(fileToWrite);
   }
   fclose(file);
   return 0;
}
