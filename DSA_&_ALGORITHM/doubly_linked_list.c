#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;

};

// _______________ DOUBLY LINK LIST INSERTION _______________ //

struct Node* insert_at_first(struct Node* Head, int value){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = value;
    temp->prev = NULL;
    if(Head==NULL){
        Head = temp;
    }
    else{
        temp->next = Head;
        temp->prev = NULL;
        Head->prev = temp;
        Head = temp;
    }
    return Head;
}

struct Node* insert_at_last(struct Node* Head, int value){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = value;
    temp->prev = NULL;
    if(Head==NULL){
        Head = temp;
    }
    else{
        struct Node* ptr = Head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        temp->prev = ptr;
        ptr->next = temp;
    }
    return Head;
}

struct Node* insert_at_middle(struct Node* Head, int value, int idx){
    if(idx==0){
        Head = insert_at_first(Head,value);
    }
    else{
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->data = value;
        temp->next = NULL;
        struct Node* ptr = Head;
        for(int i=1; i<idx; i++){
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        ptr = ptr->next;
        temp = temp->next;
        temp->prev = ptr;
    }
    return Head;

}
// _______________ INSERTION END _______________ //

// _______________ DISPLAY _______________ // 

void display(struct Node* Head){
    if(Head==NULL) return;
    while(1){
        printf("%d ", Head->data);
        if(Head->next == NULL) break;
        Head = Head->next;
    }
    printf("<---> ");
    while(Head != NULL){
        printf("%d ", Head->data);
        Head = Head->prev;
    }
    printf("\n");
}

// void display(struct Node* Head){ // RECURSIVE TRAVERSAL FOR DISPLAY THE ELEMENT'S
//     if(Head == NULL){
//         printf("<---> ");
//         return ;
//     }
//     printf("%d ",Head->data);
//     display(Head->next);
//     printf("%d ",Head->data);
// }

// _______________ DISPLAY _______________ // 

// _______________ DOUBLY LINK LIST DELETION _______________ //

struct Node* delete_first(struct Node* Head){
    struct Node* temp = Head;
    Head = Head->next;
    Head->prev = NULL;
    free(temp);
    return Head;
}

struct Node* delete_middle(struct Node* Head, int idx){ 
    if(idx==0){
        Head = delete_first(Head);
    }
    else{

        struct Node* ptr_prev = Head;
        struct Node* ptr_current = ptr_prev->next;
        struct Node* ptr_next = ptr_current->next;
        for(int i=1; i<idx; i++){
            ptr_prev = ptr_prev->next;
            ptr_current = ptr_current->next;
            ptr_next = ptr_next->next;
        }
        ptr_prev->next = ptr_next;
        ptr_next->prev = ptr_prev;
        free(ptr_current);

    }
    return Head;

}

struct Node* delete_last(struct Node* Head){
    struct Node* p = Head;
    struct Node* q = Head->next;
    while(q->next !=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return Head;
}


struct Node* delete_element(struct Node* Head, int value){
    struct Node* ptr = Head;
    while(ptr->data != value && ptr != NULL){
        ptr = ptr->next;
    }
    if(ptr==NULL){
        printf("Element not in the list!");
    }
    else{
        struct Node* prev_ptr = ptr->prev;
        struct Node* next_ptr = ptr->next;
        prev_ptr->next = next_ptr;
        next_ptr->prev = prev_ptr;
        free(ptr);
    }
    return Head;
}
    
// _______________ DELETION END _______________ //

int main(){

    // _______________ DOUBLY LINK LIST INSERTION _______________ //

    struct Node* Head = NULL;

    Head = insert_at_first(Head,10);
    Head = insert_at_first(Head,20);
    Head = insert_at_first(Head,30);

    display(Head);

    Head = insert_at_last(Head,50);
    Head = insert_at_last(Head,50);
    Head = insert_at_last(Head,50);

    display(Head);
        

    Head = insert_at_middle(Head,33,3);
    Head = insert_at_middle(Head,33,3);
    Head = insert_at_middle(Head,33,3);

    display(Head);
        
    // _______________ INSERTION END _______________ //

    // _______________ DOUBLY LINK LIST DELETION _______________ //

    Head = delete_first(Head);
    display(Head);
    Head = delete_last(Head);
    display(Head);
    Head = delete_middle(Head,1);
    display(Head);
    Head = delete_element(Head,33);
    display(Head);

    // _______________ DELETION END _______________ //



    return 0;
}