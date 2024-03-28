#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct queue{
    Node *font;
    Node *rear;
}queue;

queue * init(){
    queue * temp = (queue*) malloc(sizeof(queue));
    if(temp == NULL){
        printf("Memory is full!\n");
        return NULL;
    }
    temp->font = NULL;
    temp->rear = NULL;
    return temp;
}

int isempty(queue *obj){
    if(obj->font == NULL && obj->rear == NULL) return 1;
    else return 0;
}

int isfull(queue *obj){
    Node *temp = (Node *) malloc(sizeof(Node));
    if(temp==NULL) return 1;
    else{
        free(temp);
        return 0;
    }
}

int font(queue *obj){
    if(isempty(obj)){
        printf("Queue is Empty!\n");
        return -1;
    }
    return (obj->font)->data;
}

int rear(queue *obj){
    if(isempty(obj)){
        printf("Queue is Empty!\n");
        return -1;
    }
    return (obj->rear)->data;
}

void enqueue(queue *obj, int data){
    Node* temp = (Node *) malloc(sizeof(Node));
    if(temp==NULL){
        printf("Queue Overflow!\n");
        return ;
    }
    else if(obj->font == NULL && obj->rear == NULL){
        temp->data = data;
        temp->next = NULL;
        obj->font = obj->rear = temp;
    }
    else{
        temp->data = data;
        temp->next = NULL;
        (obj->rear)->next = temp;
        obj->rear =  temp;
    }
}

int dequeue(queue *obj){
    if(obj->font == NULL && obj->rear == NULL){
        printf("Queue Underflow!\n");
        return -1;
    }
    else{
        Node *temp = obj->font;
        obj->font = (obj->font)->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}


int main(){

    queue *obj = init();
    printf("isempty : %d\n",isempty(obj));
    printf("isfull : %d\n",isfull(obj));
    printf("font : %d\n", font(obj));
    printf("rear : %d\n", rear(obj));
    enqueue(obj,55);
    printf("isempty : %d\n",isempty(obj));
    printf("isfull : %d\n",isfull(obj));
    printf("font : %d\n", font(obj));
    printf("rear : %d\n", rear(obj));
    enqueue(obj,65);
    enqueue(obj,5);
    enqueue(obj,5);
    enqueue(obj,56);
    dequeue(obj);
    printf("isempty : %d\n",isempty(obj));
    printf("isfull : %d\n",isfull(obj));
    printf("font : %d\n", font(obj));
    printf("rear : %d\n", rear(obj));
    enqueue(obj,5);

    return 0;
}