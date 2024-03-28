#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int font;
    int rear;
    int *arr;
}queue;


queue * init(int size){
    queue *temp = (queue *) malloc(sizeof(queue));
    temp->size = size;
    temp->font = temp->rear = -1;
    temp->arr = (int *) malloc(sizeof(int)*size);
}

int isfull(queue *obj){
    if(obj->rear == obj->size-1) return 1;
    else return 0;
}
int isempty(queue *obj){
    if(obj->rear == obj->font) return 1;
    else return 0;
}

void enqueue(queue *obj, int value){
    if(isfull(obj)) printf("Queue overflow!\n");
    else obj->arr[++obj->rear] = value;
}

int dequeue(queue * obj){
    if(isempty(obj)) printf("Queue underflow!\n");
    else ++obj->font;
}

int font(queue *obj){
    if(isempty(obj)) return -1;
    else{
        int font = obj->font;
        return obj->arr[++font];
    }
}

int rear(queue *obj){
    if(isempty(obj)) return -1;
    else{
        int rear = obj->rear;
        return obj->arr[rear];
    }
}


int main(){

    queue *obj = init(5);
    printf("isempty : %d\n",isempty(obj));
    printf("isfull : %d\n",isfull(obj));
    printf("font %d\n", font(obj));
    printf("rear %d\n", rear(obj));
    enqueue(obj,55);
    printf("isempty : %d\n",isempty(obj));
    printf("isfull : %d\n",isfull(obj));
    printf("font %d\n", font(obj));
    printf("rear %d\n", rear(obj));
    enqueue(obj,65);
    enqueue(obj,5);
    enqueue(obj,5);
    enqueue(obj,56);
    dequeue(obj);
    printf("isempty : %d\n",isempty(obj));
    printf("isfull : %d\n",isfull(obj));
    printf("font %d\n", font(obj));
    printf("rear %d\n", rear(obj));
    enqueue(obj,5);

    return 0;
}