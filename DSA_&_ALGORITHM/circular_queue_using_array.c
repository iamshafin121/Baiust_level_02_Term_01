#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int font;
    int rear;
    int* arr;
}queue;

queue * init(int size){
    queue * temp = (queue *) malloc(sizeof(queue));
    if(temp == NULL){
        printf("Memory Full!\n");
        return NULL;
    }
    else{
        temp->size = size+1;
        temp->font = 0;
        temp->rear = 0;
        temp->arr = (int *) malloc(size * sizeof(int));
        return temp;
    }
}

int isempty(queue *obj){
    if(obj->font == obj->rear) return 1;
    else return 0;
}

int isfull(queue *obj){
    if((obj->font) == (obj->rear+1)%obj->size) return 1;
    else return 0;
}

void enqueue(queue *obj, int value){
    if(isfull(obj)){
        printf("Queue Overflow!\n");
    }
    else{
        obj->arr[obj->rear] = value;
        obj->rear = (obj->rear + 1) % obj->size;
    }
}

int dequeue(queue *obj){
    int x = -1;
    if(isempty(obj)){
        printf("Queue Underflow!\n");
    }
    else{
        x = obj->arr[obj->font];
        obj->font = (obj->font+1)%obj->size;
    }
    return x;
}

int font(queue *obj){
    if(isempty(obj)) return -1;
    return obj->arr[obj->font];
}

int rear(queue *obj){
    if(isempty(obj)) return -1;
    return obj->arr[obj->rear - 1];
}

int main(){

    queue *obj = init(5);
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
    enqueue(obj,5);
    printf("isfull : %d\n",isfull(obj));

    return 0;
}