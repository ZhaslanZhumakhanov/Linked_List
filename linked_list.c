#include "list.h"
#include <stdlib.h>

// В узле списка хранится само значение value и указатель на следующий узел.
// Эту структуру пользователи списка не должны видеть, так как она относится к внутренней реализации.
typedef struct Node_ {
  int value; // само значение, которое хранит узел
  struct Node_ *next; // указатель на следующий узел
} Node;

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  Node *head; // указатель на голову списка
  Node *tail; // указатель на хвост списка
};

List *NewList(){
    List* list=malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    return list;
}

void DestroyList(List* this) {
    Node* tmp=this->head;
    while (tmp!=NULL){
        tmp=tmp->next;
        free(this->head);
        this->head=tmp;
    }
    this->tail=NULL;
    free(this);
}

void Append(List *this, int value) {
    Node* tmp=malloc(sizeof(Node));
    tmp->next=NULL;
    tmp->value=value;
    if (this->head==NULL){
        this->head=tmp;
        this->tail=tmp;
    }
    else{
        this->tail->next=tmp;
        this->tail=tmp;
    }
}

void Prepend(List *this, int value) {
    Node *tmp=malloc(sizeof(Node));
    tmp->value=value;
    if (this->head==NULL){
        this->head=tmp;
        this->tail=tmp;
    }
    else {
        tmp->next=this->head;
        this->head=tmp;
    }
}
void AppendAll(List *this, const List *that) {
    if (that->head==NULL){ return;}
    if (this->head==NULL) {
        this->head=that->head;
        this->tail=that->tail;
    }
    else{
        this->tail->next=that->head;
        this->tail=that->tail;
    }
}
void InsertAt(List *this, int index, int value) {
    //TODO: напиши меня!
}

void RemoveAt(List *this, int index) {
    //TODO: напиши меня!
}
void RemoveAll(List *this) {
    //TODO: напиши меня!
}

int Pop(List *this) {
    //TODO: напиши меня!
}
int Dequeue(List *this) {
    //TODO: напиши меня!
}

int Length(const List *this) {
    if (this->head==NULL){ return 0;}
    Node* tmp=this->head;
    int count=0;
    while (tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}

int GetAt(const List *this, int index) {
    if (this->head==NULL || index>=Length(this)) {exit(-1);}
    Node* tmp=this->head;
    for (int i=0; i<index; i++) {
        tmp = tmp->next;
    }
    return tmp->value;
}
