// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { return NULL; }
void list_free(list_t *l) {
  node_t* current = l->head;

  while (current != NULL) {
    node_t* temp = current;
    current = current->next;
    free(temp);

  l->head = NULL;
}

void list_print(list_t *l) {

  node_t* current = l->head;

  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
    }

  printf("NULL\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* current = l->head;
  while (current != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    current = current->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  int length = 0;
  node_t* current = l->head;
  while (current != NULL) {
        length++; 
        current = current->next; 
    }
  return -1; }

void list_add_to_back(list_t *l, elem value) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  if (l->head == NULL) {
    l->head = new_node;
    } 
  else {
    node_t* current = l->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t * curr_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;
  
  node_t* head = l->head;
  head = curr_node;
}
void list_add_at_index(list_t *l, elem value, int index) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;

  if (l->head == NULL || index <= 0) {
        new_node->next = l->head;
        l->head = new_node;
        return;
    }

  node_t* current = l->head;
    int current_index = 0;

    while (current->next != NULL && current_index < index - 1) {
        current = current->next;
        current_index++;
    }
  new_node->next = current->next;
  current->next = new_node;
}

elem list_remove_from_back(list_t *l) { 
  elem removed;
  node_t* current = l->head;

  while (current->next->next != NULL) {
    current = current->next;
    }
  removed = current->next->value;
    free(current->next);
    current->next = NULL;

    return removed;
  return -1; }

elem list_remove_from_front(list_t *l) { 
  elem removed;

  removed = l->head->value;

  node_t* temp = l->head;
  l->head = l->head->next;

  free(temp);

  return removed;
  
  return -1; }
elem list_remove_at_index(list_t *l, int index) { 
  elem removed;

  if (index == 0) {
    list_remove_from_front(list_t *l)
    }

  node_t* current = l->head;
  int current_index = 0;

  while (current->next != NULL && current_index < index - 1) {
    current = current->next;
    current_index++;
    }
  if (current->next == NULL) {
    return removed;
    }
  removed = current->next->value;
  node_t* temp = current->next;
  current->next = current->next->next;
  free(temp);
  return -1; }

bool list_is_in(list_t *l, elem value) { 
  node_t* current = l->head;

  while (current != NULL) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false; }
elem list_get_elem_at(list_t *l, int index) { 
  int current_index = 1;
  node_t* current = l->head;

  while (current != NULL && current_index < index) {
    current = current->next;
    current_index++;
    }
  if (current != NULL) {
    return current->value;
    } 

  return -1; }
int list_get_index_of(list_t *l, elem value) { 
  int current_index = 1;
  node_t* current = l->head;

  while (current != NULL) {
    if (current->value == value) {
      return current_index;
      }
    current = current->next;
    current_index++;
    }

  return -1; }

