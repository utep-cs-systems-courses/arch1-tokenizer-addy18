#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// true if c is a tab or space, not zero
int space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
      return 1;
   }
   return 0;
}

//true if c not a tab or space, and not zero
int non_space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
      return 0;
   }
   return 1;
}

// * to first (non-space) char in first word in s
char *word_start(char *str){
   int i = 0;
   while(space_char(str[i])) i++;
   printf("start\n");
   return &str[i];
}

// * to char after end of word --- look back 
char *word_terminator(char *word){
  int i = 0;
  while(non_space_char(word[i])) i++;
 
  return &word[i];
}

// the number of words in s
int count_words(char *s){
  int count = 0;
  int i = 0;
  while(s[i] != '\0'){
    if(space_char(s[i]) && non_space_char(s[i+1]))
       count++;
       i++;
  }
  count++;
  return count;
}

char *copy_str(char *inStr, short len){
  char *outputString = malloc((len+1) *sizeof(char));
  int i = 0;
  while(i <= len){
    outputString[i] = inStr[i];
    i++;
  }
  return outputString;
}

char **tokenize(char *str){
  int index, len;
  int totalIndex = count_words(str);

  char **tokens = malloc((totalIndex + 1) * sizeof(char*));
  char *strpointer = str;

  int i;
  for(i = 0; i < totalIndex; i++){
    strpointer = word_start(strpointer);
    len = (word_terminator(strpointer) - word_start(strpointer));
    tokens[i] = copy_str(strpointer, len);
    strpointer = word_terminator(strpointer);
  }
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens){
  int index = 0;
  while(tokens[index] != NULL){
    printf("%s\n", tokens[index]);
    index++;
  }
}

void free_tokens(char **tokens){
  int index = 0;
  for(index = 0; tokens[index] != 0; index++){
    free(tokens[index]);
  }
  free(tokens);
}
