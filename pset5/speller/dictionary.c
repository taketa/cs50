/**
* Implements a dictionary's functionality.
*/

#include <stdbool.h>

#include "dictionary.h"

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>




int hash(const char* word);
const int HASHTABLE = 26;
int count = 0;
char word[LENGTH];

struct node{
    char *word;
    struct node* next;
};

struct node *hashTable[HASHTABLE];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    struct node* wordFromDictionary = malloc(sizeof(struct node));
    int box = hash(word);
    wordFromDictionary = hashTable[box];
    while (wordFromDictionary != NULL){
        if (strcasecmp(wordFromDictionary->word, word) == 0)
            return true;
        wordFromDictionary = wordFromDictionary->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
        return false;
    while (fscanf(dict, "%s\n", word) != EOF){
        struct node *new = malloc(sizeof(struct node));
        new->word = malloc(strlen(word) + 1);

        strcpy(new->word, word);
        int hashValue = hash(word);

        if (hashTable[hashValue] == NULL){
            new->next = NULL;
            hashTable[hashValue] = new;
        }
        else{
            new->next = hashTable[hashValue];
            hashTable[hashValue] = new;
        }
        count++;
    }
    fclose(dict);
    return true;
}

int hash(const char* word)
{
    int index = tolower(word[0])-'a';
    return index;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO

    for (int i = 0; i < HASHTABLE; i++){
        struct node *cursor = hashTable[i];
        while (cursor != NULL){
            struct node* temp = cursor;
            cursor = cursor->next;
            free(temp);
            return true;
        }
    }
    return false;
}
