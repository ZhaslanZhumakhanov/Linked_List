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
    tmp->next=NULL;
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
    for (int i=0; i<Length(that);i++) {
        Append(this,GetAt(that,i));
    }
}
void InsertAt(List *this, int index, int value) {
    if (index<0 || index>=Length(this)){
        exit(-1);
    }
    Node* tmp=this->head;
    for (int i=0; i<index; i++){
        tmp=tmp->next;
    }
    Node* that=malloc(sizeof(Node));
    that->value=value;
    that->next=tmp->next;
    tmp->next=that;
    if (index==(Length(this)-2)){
        this->tail=that;
    }
}

void RemoveAt(List *this, int index) {
    Node* tmp=this->head;
    if (index==0){
        this->head=this->head->next;
        tmp->next=NULL;
        free(tmp);
        return;
    }
    for (int i=0; i<index-1; i++){
        tmp=tmp->next;
    }
    Node* tmp2=tmp->next;
    tmp->next=tmp2->next;
    free(tmp2);
    if (index==Length(this)){
        this->tail=tmp;
    }
}
void RemoveAll(List *this) {
    Node* tmp=this->head;
    for (int i=0; i<Length(this)-1;i++){
        tmp=tmp->next;
        free(this->head);
        this->head=tmp;
    }
    this->tail=NULL;
    this->head=NULL;
    free(tmp);
}

int Pop(List *this) {
    if (Length(this)==0){
        exit(-1);
    }
    int value=this->tail->value;
    Node* tmp=this->head;
    for (int i=0; i<Length(this)-2; i++){
        tmp=tmp->next;
    }
    free(this->tail);
    tmp->next=NULL;
    this->tail=tmp;
    return value;
}

int Dequeue(List *this) {
    if (this->head==NULL){
        exit(-1);
    }
    int value=this->head->value;
    Node* tmp=this->head->next;
    free(this->head);
    this->head=tmp;
    if (Length(this)==1){
        this->tail=tmp;
    }
    return value;
}

int Length(const List *this) {
    if (this->head==NULL){
        return 0;
    }
    Node* tmp=this->head;
    int count=0;
    while (tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}

int GetAt(const List *this, int index) {
    if (this->head==NULL || index>=Length(this)) {
        exit(-1);
    }
    Node* tmp=this->head;
    for (int i=0; i<index; i++) {
        tmp = tmp->next;
    }
    return tmp->value;
}
