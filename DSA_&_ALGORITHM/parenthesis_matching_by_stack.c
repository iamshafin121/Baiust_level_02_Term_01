#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

//______ Some linked list operation for this task ______//

Node* insert_at_first(Node* head, char value){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}

Node* reverse(Node* head){
    Node* p = NULL;
    Node* q = head;
    Node* r = head;
    while(q!=NULL){
        r = r->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}
//______ linked list operations end _____//

//______________ STACK IMPLIMANTIATION _________________//

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

void push(stack *obj, char value){
    if(isfull(obj)){
        printf("Stack overflow!\n");
        return;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = value;
    temp->next = obj->top;
    obj->top = temp;
}

char pop(stack *obj){
    if(isempty(obj)){
        printf("Stack underflow!\n");
        return '0';
    }
    Node *temp = obj->top;
    obj->top = (obj->top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

char top(stack *obj){
    if(isempty(obj)){
        return '0';
    }
    else{
        return (obj->top)->data;
    }
}

char bottom(stack *obj){
    if(isempty(obj)){
        return '0';
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
//______________ STACK IMPLIMANTIATION DONE_________________//

int check_paranthesis_match(Node *Head){
    stack *store = init();

    while(Head != NULL){
        if(Head->data == '(' || Head->data == '{' || Head->data == '['){
            push(store,Head->data);
        }
        else if(Head->data == ')' || Head->data == '}' || Head->data == ']'){
            if(isempty(store)) return 0;
            else{
                char poped = pop(store);
                if(!((poped == '(' && Head->data == ')') || (poped == '{' && Head->data == '}') || (poped == '[' && Head->data == ']'))) return 0;
            }
        }

        // _____ Alternative elseif condition _____//
        
        // else if(Head->data == ')'){
        //     if(isempty(store)) return 0;
        //     else{
        //         char c = pop(store);
        //         if(c != '(') return 0;
        //     }
        // }
        // else if(Head->data == '}'){
        //     if(isempty(store)) return 0;
        //     else{
        //         char c = pop(store);
        //         if(c != '{') return 0;
        //     }
        // }
        // else if(Head->data == ']'){
        //     if(isempty(store)) return 0;
        //     else{
        //         char c = pop(store);
        //         if(c != '[') return 0;
        //     }
        // }


        Head = Head->next;
    }
    if(isempty(store)) return 1;
    else return 0;

}


int main(){
    // Initializing linked list
    Node *Head = NULL;

    printf("Enter Expression : ");
    // Taking input in linked list


    char c;

    // while((c = getchar()) != '\n' && c != EOF){
    //     Head = insert_at_first(Head,c);
    // }

    while(1){ // Alternative while loop
        scanf("%c",&c);
        if(c=='\n') break;
        Head = insert_at_first(Head,c);
    }



    // Reverse the linked list
    Head = reverse(Head);


    // Check paranthesis matching 
    if(check_paranthesis_match(Head)){
        printf("Paranthesis matched!\n");
    }
    else{
        printf("Paranthesis doesn't match!\n");
    }


    
    return 0;
}


