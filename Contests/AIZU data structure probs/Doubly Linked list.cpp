#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *next;
    node *prev;
};
node *head = NULL, *tail = NULL;

void insertFirst(int data){
    node *newNode = new node();
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    if(head==NULL){
        head = tail = newNode;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void deleteFirst(){
    if(head == NULL) return;
    node *temp = head;
    if(head == tail){
        head = tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

void deleteLast(){
    if(tail == NULL) return;
    node *temp = tail;
    if(head == tail){
        head = tail = NULL;
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void deleteX(int val){
    node *traverser = head, *temp = NULL;
    while(traverser != NULL){
        if(traverser->data==val){
            temp = traverser;
            break;
        }
        traverser = traverser->next;
    }
    if(temp != NULL){
        if(temp==head) deleteFirst();
        else if(temp==tail) deleteLast();
        else{
            node *first, *second;
            first = temp->prev;
            second = temp->next;
            first->next = second;
            second->prev = first;
            free(temp);
        }
    }
}

void print(){
    node *traverser = head;
    int flag = 0;
    while(traverser != NULL){
        if(flag) printf(" ");
        else flag = 1;
        printf("%d", traverser->data);
        traverser = traverser->next;
    }
    printf("\n");
}

int main(){
    FILE *inp = freopen("dli.txt", "r", stdin);
    int n, num;
    char cmd[20];
    scanf("%d\n", &n);
    while(n--){
        scanf("%s", cmd);
        if(strcmp(cmd, "deleteFirst")==0) deleteFirst();
        else if(strcmp(cmd, "deleteLast")==0) deleteLast();
        else {
            scanf("%d\n", &num);
            if(strcmp(cmd, "delete")==0) deleteX(num);
            else if(strcmp(cmd, "insert")==0) insertFirst(num);
        }
    }
    print();
    //fclose(inp);
    return 0;
}
