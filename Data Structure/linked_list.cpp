#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    node *next;
    int data;
};
node *header, *traverser;

void insertFirst(int data);
void insertLast(int data);
void deleteFirst();
void deleteLast();
void print();

int main(){
    //initially declaring the list null / void ..
    header = NULL;

    insertFirst(2);
    insertFirst(5);
    insertFirst(10);
    deleteLast();
    print();
}

void insertFirst(int data){
    if(header==NULL){
        header = new node();
        header->next = NULL;
        header->data = data;
    }
    else{
        node *temp = header;
        header = new node();
        header->data = data;
        header->next = temp;
    }
}

void insertLast(int data){
    if(header==NULL){
        header = new node();
        header->data = data;
        header->next = NULL;
    }
    else{
        traverser = header;
        while(traverser->next != NULL){
            traverser = traverser->next;
        }
        traverser->next = new node();
        traverser->next->next = NULL;
        traverser->next->data = data;
    }
}

void deleteFirst(){
    if(header==NULL){
        printf("list is already empty.\n");
    }
    else{
        node *temp = header;
        header = header->next;
        free(temp);
    }
}

void deleteLast(){
    if(header==NULL){
        printf("list is already empty.\n");
    }
    else{
        traverser = header;
        node *sec_last;
        while(traverser->next != NULL){
            sec_last = traverser;
            traverser = traverser->next;
        }
        sec_last->next = NULL;
        free(traverser);
    }
}

void print(){
    if(header==NULL){
        printf("no element to print\n");
    }
    else{
        traverser = header;
        while(1){
            printf("%d  ->  ", traverser->data);
            if(traverser->next == NULL)
                break;
            traverser = traverser->next;
        }
    }
}
