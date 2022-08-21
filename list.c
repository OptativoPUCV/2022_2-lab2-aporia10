#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List*L=(List*)malloc(sizeof(List));
  L->head=NULL;
  L->current=NULL;
  return L;
}
void * firstList(List * list) {
  Node * nodo;
  nodo=list->head;
  list->current=nodo;
  if (list->head==NULL){
    return NULL;
  }
  else{
    int * dato;
    dato=nodo->data;
    return dato;
  }
}

void * nextList(List * list) {
  if(list->current==NULL){
    return NULL;
  }
  else{
    Node * nodo;
    nodo=list->current->next;
    list->current=nodo;
    if(list->current==NULL){
      return NULL;
    }
    else{
      int * dato;
      dato=nodo->data;
      return dato;
    }
  }
}

void * lastList(List * list) {
  Node * nodo;
  nodo=list->tail;
  list->current=nodo;
  if (list->tail==NULL){
    return NULL;
  }
  else{
    int * dato;
    dato=nodo->data;
    return dato;
  }
}

void * prevList(List * list) {
  if(list->current==NULL){
    return NULL;
  }
  else{
    Node * nodo;
    nodo=list->current->prev;
    list->current=nodo;
    if(list->current==NULL){
      return NULL;
    }
    else{
     int * dato;
     dato=nodo->data;
     return dato;
  }
 }
}
void pushFront(List * list, void * data) {
  Node * nodo=createNode(data);
  if(list==NULL){
    list->head=nodo;
    list->tail=nodo;
  }
  else{
    list->head->prev=nodo;
    nodo->next=list->head;
    list->head=nodo;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}