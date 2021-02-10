#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// true if c is a tab or space, not zero
int space_char(char c){
   if(c == ' ' || c == '\t'){
      return 1;
   }
   return 0;
}

//true if c not a tab or space, and not zero
int non_space_char(char c){
   if(c != ' ' || c != '\t'){
      return 1;
   }
   return 0;
}

// * to first (non-space) char in first word in s
char word_start(char *str){
   while(space_char(*str)){
     str++;
   }
   return *str;
}

// * to char after end of word
char *word_terminator(char *word){}

// the number of words in s
int count_words(char *s){}
