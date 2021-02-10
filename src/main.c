#include <stdio.h>

int main(){
  char str[50];
  int choice;
  
  while(1){
    printf("Select an option: \n");
    printf("1. tokenize a string\n");
    printf("2. string history\n");
    printf("3. exit\n");
    scanf("%d", &choice);
    printf("\n");

    if(choice == 1){
      printf("Enter a string:\n");
      printf("> ");
      fgets(str, 50, stdin);

      printf("%s\n", str);
    }else if(choice == 2){
      printf("history\n");
    }else if(choice == 3){
      printf("Goodbye :)\n");
      goto done;
    }
  }
    
  done:
    return 0;
}
