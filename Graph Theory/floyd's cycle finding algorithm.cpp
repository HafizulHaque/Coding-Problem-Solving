#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *next;
};

node *_insert(int data);
void cycle_detect();

node *root;

int main(){
    root = NULL;
    node *a, *b;

    _insert(1);
    _insert(2);
    _insert(3);                    // 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9
    _insert(4);                    //                     |           |
    _insert(5);                    //                     12 - 11 -- 10
    a = _insert(6);
    _insert(7);
    _insert(8);
    _insert(9);
    _insert(10);
    _insert(11);
    b = _insert(12);

    b->next = a;

    cycle_detect();
}

node *_insert(int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if(root==NULL){
        root = temp;
        return root;
    }
    else{
        node *traverser = root;
        while(traverser->next != NULL){
            traverser = traverser->next;
        }
        traverser->next = temp;
        return temp;
    }
}

void cycle_detect(){
    node *har = root, *tor = root , *_union;

    if(root==NULL){
        cout << "No binary tree found.\n" << endl;
        return;
    }

    while(1){
        tor = tor->next;
        for(int i = 0; i < 2; ++i){
            if(har->next==NULL){
                cout << "No cycle.\n" << endl;
                return;
            }
            har = har->next;
        }
        if(har==tor){
            _union = har;
            break;
        }
    }
    har = _union;
    tor = root;

    while(har != tor){
        har = har->next;
        tor = tor->next;
    }

    cout << har->data << endl;

}
