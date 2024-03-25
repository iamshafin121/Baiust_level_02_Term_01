#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct stack{
    Node *top;
}stack;

stack * init(){
    stack *obj = (stack *) malloc(sizeof(stack));
    obj->top = NULL;
    return obj;
}

int isempty(stack *obj){
    if(obj->top == NULL) return 1;
    else return 0;
}

int isfull(stack *obj){
    Node *temp = (Node *) malloc(sizeof(Node));
    if(temp == NULL){
        return 1;
    }
    else{
        free(temp);
        return 0;
    }
}

void push(stack *obj, int value){
    if(isfull(obj)){
        printf("Stack overflow!\n");
        return;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = value;
    temp->next = obj->top;
    obj->top = temp;
}

int pop(stack *obj){
    if(isempty(obj)){
        printf("Stack underflow!\n");
        return -1;
    }
    Node *temp = obj->top;
    obj->top = (obj->top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int top(stack *obj){
    if(isempty(obj)){
        return -1;
    }
    else{
        return (obj->top)->data;
    }
}

int bottom(stack *obj){
    if(isempty(obj)){
        return -1;
    }
    else{
        Node *ptr = obj->top;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        return ptr->data;
    }
}

int peek(stack *obj, int idx){

    Node *ptr = obj->top;
    for(int i=1; (i<idx && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Invalid Index!\n");
        return -1;
    }
    else{
        return ptr->data;
    }

}

int main(){

    stack *a = init();
    if(isempty(a)) printf("Stack is empty!!\n");
    else printf("Stack is not empty!!\n");
    push(a,10);
    push(a,20);
    push(a,30);
    push(a,40);
    push(a,50);
    pop(a);

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