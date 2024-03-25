#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

stack* init(int size){

    stack *mam_alloc =(stack*) malloc(sizeof(stack));
    mam_alloc->top = -1;
    mam_alloc->size = size;
    mam_alloc->arr = (int *) malloc(sizeof(int)*size);

    return mam_alloc;
}

int isempty(stack *obj){
    if(obj->top == -1) return 1;
    return 0;
}
int isfull(stack *obj){
    if(obj->top == obj->size-1) return 1;
    return 0;
}

void push(stack *obj,int data){
    if(obj->top >= obj->size-1){
        printf("Stack overflow!\n");
        return ;
    }
    obj->arr[++obj->top] = data;
}
int pop(stack *obj){
    if(obj->top <= -1){
        printf("Stack underflow!\n");
        return -1;
    }
    return obj->arr[obj->top--];
}

int peek(stack *obj, int idx){
    if((obj->top-idx+1) < 0){
        printf("Invalid Index!\n");
        return -1;
    }
    else{
        return obj->arr[obj->top-idx+1];
    }
}

int top(struct stack* obj){
    return obj->arr[obj->top];
}
int bottom(struct stack* obj){
    return obj->arr[0];
}

int main(){

    stack *a = init(5);
    push(a,10);
    push(a,20);
    push(a,30);
    push(a,40);
    push(a,50);
    // pop(a);

    if(isempty(a)) printf("Stack is empty!!\n");
    else printf("Stack is not empty!!\n");
    if(isfull(a))printf("Stack is full!!\n");
    else printf("Stack is not full!!\n");
    int x = peek(a,5);
    printf("value : %d\n", x );
    x = peek(a,4);
    printf("value : %d\n", x );
    x = peek(a,3);
    printf("value : %d\n", x );
    x = peek(a,2);
    printf("value : %d\n", x );
    x = peek(a,1);
    printf("value : %d\n", x );
    x = peek(a,6);
    printf("value : %d\n", x );
    printf("Top value : %d\n", top(a) );
    printf("Bottom value : %d\n", bottom(a) );
    return 0;
}