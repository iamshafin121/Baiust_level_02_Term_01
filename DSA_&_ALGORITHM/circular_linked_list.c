#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insert_at_first_or_last(struct Node* Head, int value){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(Head == NULL){
        temp->next = temp; // If i replace temp by Head why problem occurs ??
        Head = temp;
    }
    else{
        struct Node* ptr = Head;
        temp->next = ptr;
        while(ptr->next != Head){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return Head;
}

struct Node* insert_at_middle(struct Node* ptr, int value, int idx){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    struct Node* ptr_2 = ptr;
    for(int i=0; i<idx-1; i++){
        ptr_2 = ptr_2->next;
    }
    temp->next = ptr_2->next;
    ptr_2->next = temp;
    return ptr;

}

// _______________ LINK LIST DELETION _______________ //
struct Node* delete_first(struct Node* Head){
    struct Node* ptr = Head;
    Head = Head->next;
    struct Node* ptr_2 = Head;
    while(ptr_2->next != ptr){
        ptr_2 = ptr_2->next;
    }
    ptr_2->next = Head;
    free(ptr);
    return Head;
}

struct Node* delete_middle(struct Node* Head, int idx){
    struct Node* prev_ptr = Head;
    for(int i=1; i<idx; i++){
        prev_ptr = prev_ptr->next;
    }
    struct Node* current_ptr = prev_ptr->next;
    prev_ptr->next = current_ptr->next;
    free(current_ptr);
    return Head;
}

struct Node* delete_end(struct Node* Head){
    struct Node* prev_ptr = Head;
    struct Node* current_ptr = prev_ptr->next;
    while(current_ptr->next != Head){
        prev_ptr = prev_ptr->next;
        current_ptr = current_ptr->next;
    }
    prev_ptr->next = current_ptr->next;
    free(current_ptr);
    return Head;
}

struct Node* delete_element(struct Node* Head, int value){
    struct Node* prev_ptr = Head;
    if(Head->data == value){
        Head = Head->next;
        free(prev_ptr);
        return Head;
    }
    struct Node* current_ptr = prev_ptr->next;
    while(current_ptr->data != value && current_ptr != Head){
        prev_ptr = prev_ptr->next;
        current_ptr = current_ptr->next;
    }
    if(current_ptr->data == value){
        prev_ptr->next = current_ptr->next;
        free(current_ptr);
    }
    return Head;
}
// _______________ DELETION END _______________ //

void display(struct Node* Head){
    if(Head==NULL){
        return;
    }
    else{
        struct Node* ptr = Head;
        do{
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }while(ptr != Head);
        printf("\n");
    }
}

int main(){

    struct Node* Head = NULL;
    Head = insert_at_first_or_last(Head, 10);
    Head = insert_at_first_or_last(Head, 20);
    Head = insert_at_first_or_last(Head, 30);
    Head = insert_at_first_or_last(Head, 40);
    Head = insert_at_first_or_last(Head, 50);
    display(Head);

    Head = insert_at_middle(Head, 55, 2);
    display(Head);

    Head = delete_middle(Head,2);
    display(Head);

    Head = delete_first(Head);
    display(Head);

    Head = delete_end(Head);
    display(Head);

    Head = delete_element(Head,55);
    display(Head);

  
    
    return 0;
}