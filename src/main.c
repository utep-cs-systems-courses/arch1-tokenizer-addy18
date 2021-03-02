#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char str[50];
  int choice;
  List *list = init_history();
  int flag = 1;
  

   printf("Select an option:");
   while(1){
     printf("Select an option:\n 't' tokenize, 'h' history, 'v' view history, 'q' quit \n");
     fgets(str, 50, stdin);

     switch(str[0]){
     case 't':
	 printf("enter a sentence: \n>");
	 fgets(str, 50, stdin);
	 char **token = tokenize(str);
	 print_tokens(token);
	 add_history(list, str);
	 free_tokens(token);
	 break;

     case 'h':
       printf("enter id number: ");
       scanf("%d", &choice);

       char *retrieved_hist = get_history(list, choice);
       char **tokens = tokenize(retrieved_hist);

       printf("retrieved: %s\n", retrieved_hist);
       print_tokens(tokens);
       free_tokens(tokens);
       break;

     case 'v':
       print_history(list);
       break;
       
     case 'q':
	 printf("goodbye\n");
	 return 0;
	 break;
	 /*
     default:
	 printf("invalid input\n");
	 */}
   }
}
