#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    node *prev;
    node *next;
    int data;
};
node *header, *tailer, *traverser;

node *insertFirst(int data);
node *insertLast(int data);
void deleteFirst();
void deleteLast();
node *insertAt(node *ptr, int data);
void _deleteNode(node *ptr);
void print();

int main(){
    //initially declaring the list null / void ..
    header = NULL;
    tailer = NULL;

    node *a, *b, *c, *d;

    a = insertFirst(2);
    insertFirst(1);
    c = insertLast(5);
    b = insertFirst(10);
    insertFirst(7);
    d = insertLast(8);
    insertLast(11);
    deleteFirst();
    deleteLast();
    insertAt(b, 4);
    insertAt(d, 20);
    _deleteNode(a);


    print();
}

node *insertFirst(int data){
    node *temp = new node();
    temp->data = data;
    if(header==NULL){
        temp->prev = NULL;
        temp->next = NULL;
        header = temp;
        tailer = temp;
    }
    else{
        node *current = header;
        current->prev = temp;
        temp->prev = NULL;
        temp->next = current;
        header = temp;
    }

    return temp;
}

node *insertLast(int data){
    node *temp = new node();
    temp->data = data;
    if(tailer==NULL){
        temp->next = NULL;
        temp->prev = NULL;
        tailer = temp;
        header = temp;
    }
    else{
        node *current = tailer;
        current->next = temp;
        temp->next = NULL;
        temp->prev = current;
        tailer = temp;
    }

    return temp;
}

node *insertAt(node *ptr, int data){

    if(ptr==header){
        insertFirst(data);
        return header;
    }
    else{
        node *temp = new node();
        temp->data = data;
        temp->next = ptr;
        temp->prev = ptr->prev;

        ptr->prev->next = temp;
        ptr->prev = temp;

        return temp;
    }
}

void deleteFirst(){
    if(header==NULL){
        printf("list is already empty.\n");
    }
    else if(header==tailer){
        free(header);
        header = NULL;
        tailer = NULL;
    }
    else{
        node *temp = header;
        header = header->next;
        header->prev = NULL;
        free(temp);
    }
}

void deleteLast(){
    if(tailer==NULL){
        printf("list is already empty.\n");
    }
    else if(tailer==header){
        free(tailer);
        header = NULL;
        tailer = NULL;
    }
    else{
        node *temp = tailer;
        tailer = tailer->prev;
        tailer->next = NULL;
        free(temp);
    }
}


void _deleteNode(node *ptr){
    if(ptr==header&&ptr==tailer){
        header = NULL;
        tailer = NULL;
        free(ptr);
    }
    else if(ptr == header){
        header = header->next;
        header->prev = NULL;
        free(ptr);
    }
    else if(ptr == tailer){
        tailer = tailer->prev;
        tailer->next = NULL;
        free(ptr);
    }
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }

}

void print(){
    if(header==NULL){
        printf("no element to print\n");
    }
    else{
        traverser = header;
        while(traverser != NULL){
            printf("%d  ->  ", traverser->data);
            traverser = traverser->next;
        }
        printf("\n");
    }
}

