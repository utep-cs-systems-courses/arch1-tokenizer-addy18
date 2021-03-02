#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str){
  int id = 1;
  Item *node = list -> root;

  while(node -> next != NULL){
    node = node -> next;
    id++;
  }
  node -> next = malloc(sizeof(Item));
  node -> next -> str = copy_str(str, (word_terminator(str) - word_start(str)));
  node -> next -> id = id;

}

char *get_history(List *list, int id){
  int curr_id = 1;
  Item *temp = list -> root;
  while(temp -> next != NULL){
    if(curr_id = temp -> id){
      break;
    }
    temp = temp -> next;
    curr_id++;
  }
  return temp -> str;
}

void print_history(List *list){
  Item *temp = list -> root;
  while(temp != NULL){
    printf("ID: %d || %s\n", temp -> id, temp -> str);
    temp = temp -> next;
  }
}

void free_history(List *list){
  Item *temp = list -> root;
  while(temp != NULL){
    Item *tempNext = temp -> next;
    free(temp);
    temp = tempNext;
  }
  free(list);
}
