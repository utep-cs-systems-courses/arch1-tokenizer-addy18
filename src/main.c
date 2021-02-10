#include <stdio.h>

void main(){
  char str[50];

  printf("Enter a string:\n");
  printf("> ");
  fgets(str, 50, stdin);

  printf("%s\n", str);
  
}
