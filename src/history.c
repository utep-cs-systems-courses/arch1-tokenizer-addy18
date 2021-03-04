#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = malloc(sizeof(List)); //allocated memory for linked list
  list->root = NULL; //empty linked list
  return list;
}

void add_history(List *list, char *str){
  int count = 2; //placement in list
  if(list->root == NULL){
    Item *newNode = malloc(sizeof(Item));
    newNode->str = copy_str(str, (word_terminator(str) - word_start(str))); //copy string into new node
    newNode->id = 1;//inital place, first node
    newNode->next = NULL;
    list->root = newNode;
  }else{
    Item *current = list->root;
    while(current->next != NULL){
      current = current->next;
      count += 1;
    }
    current->next = malloc(sizeof(Item));
    current->next->str = copy_str(str, (word_terminator(str) - word_start(str)));
    current->next->id = count;
    current->next->next = NULL;
  }
}

char *get_history(List *list, int id){
  if(list->root == NULL){
    printf("list in empty");
  }else{
    Item *current = list->root; //traverse through the list
    while(current->next != NULL){
      if(current->id == id){ //if id matches current id return str 
	return current->str;
      }
      current = current->next; //set node to next
    }
  }
}

void print_history(List *list){
  Item *temp = list->root;
  while(temp != NULL){
    printf("ID: %d || %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  Item *temp = list->root;

  while(temp != NULL){
    Item *tempNext = temp->next;
    free(temp);
    temp = tempNext;
  }
  free(list);
}
