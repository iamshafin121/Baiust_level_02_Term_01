#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
// _______________ LINK LIST INSERTION _______________ //
struct Node* insert_at_first(struct Node* ptr, int value){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(ptr==NULL){
        ptr = temp;
    }
    else{
        temp->next = ptr;
        ptr = temp;
    }
    return ptr;
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

struct Node* insert_at_end(struct Node* head, int value){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node*));
    struct Node*  ptr = head; 
    temp->data = value;
    temp->next = NULL;
    while(ptr->next != NULL){ptr = ptr->next;}
    ptr->next = temp;
    return head;
}
// _______________ INSERTION END _______________ //

// _______________ LINKED LIST DISPLAY _______________ //
void Display_link_list(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void Display_reverse(struct Node* Head){
    if(Head == NULL) return;
    Display_reverse(Head->next);
    printf("%d ", Head->data);
}
// _______________ DISPLAY END _______________ //


// _______________ LINK LIST DELETION _______________ //
struct Node* delete_first(struct Node* Head){
    struct Node* ptr = Head;
    Head = Head->next;
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
    while(current_ptr->next != NULL){
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
    while(current_ptr->data != value){
        prev_ptr = prev_ptr->next;
        current_ptr = current_ptr->next;
    }
    prev_ptr->next = current_ptr->next;
    free(current_ptr);
    return Head;
}
// _______________ DELETION END _______________ //

// _______________ REVERSE LINK  _______________ //

struct Node* reverse_link(struct Node* Head){
    struct Node *p = NULL;
    struct Node *q = Head;
    struct Node *r = Head;
    while(q != NULL){

        r = r->next;
        q->next = p;
        p = q;
        q = r;
    }

    return p;
}

// _______________ REVERSE LINK END  _______________ //


int main(){

    struct Node *Head = NULL;

    // // Taking Input By User
    // for(int i=0; i<n; i++){
    //     printf("Enter The number : ");
    //     scanf("%d", &num);
    //     Head = insert_at_first(Head,num);
    // }
// _______________ LINK LIST INSERTION _______________ //
    Head = insert_at_first(Head,10); // Inserting element at the firstt of the linked list.
    Head = insert_at_first(Head,20); // Inserting element at the firstt of the linked list.
    Head = insert_at_first(Head,30); // Inserting element at the firstt of the linked list.
    Head = insert_at_first(Head,40); // Inserting element at the firstt of the linked list.
    Head = insert_at_first(Head,50); // Inserting element at the firstt of the linked list.

    Display_link_list(Head); // Displaying elements.

    Head = insert_at_middle(Head,55,2); // Inserting element at the middle of linked list in position 2

    Display_link_list(Head); // Displaying elements.

    Head = insert_at_end(Head,60); // Inserting element at the end of the linked list.

    Display_link_list(Head); // Displaying elements.
// _______________ INSERTION END _______________ //

// _______________ LINK LIST DELETION _______________ //
    Head = delete_first(Head);

    Display_link_list(Head);

    Head = delete_middle(Head,1);

    Display_link_list(Head);

    Head = delete_end(Head);

    Display_link_list(Head);

    Head = delete_element(Head,10);

    Display_link_list(Head);
// _______________ DELETION END _______________ //

// _______________ REVERSE LINK  _______________ //

    Head = reverse_link(Head);
    Display_link_list(Head);

// _______________ REVERSE LINK END  _______________ //

// _______________ REVERSE TRAVERSE  _______________ //

    Display_reverse(Head);
    
// _______________ REVERSE TRAVERSE END  _______________ //
    return 0;
}