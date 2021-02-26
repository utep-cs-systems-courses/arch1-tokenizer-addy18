#include <stdio.h>
#include "tokenizer.h"

int main(){
  char str[50];
  int choice;
  
   printf("Enter a string:\n");
   printf("> ");
   fgets(str, 50, stdin);

   printf("%s\n", str);

   int words = space_char(*str);
   printf("1 - true, 0 - false\n");
   printf("space char: %d\n", words);
   words = non_space_char(*str);
   printf("non space char: %d\n\n", words);

   char b = *word_start(str);
   printf("word start: %c\n", b);

   char t = *word_terminator(str);
   printf("word terminator: %c\n", t);

   int w = count_words(str);
   printf("count words: %d\n", w);
}
