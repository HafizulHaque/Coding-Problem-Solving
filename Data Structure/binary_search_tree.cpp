#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *left;
    node *right;
};
node *root;

void bst(node *ptr);
bool _insert(int data);

int main(){
    FILE *inp = freopen("bst_inp.txt", "r", stdin);
    root = NULL;
    int element;
    while(scanf("%d", &element) != EOF){
        _insert(element);
    }
    bst(root);
    fclose(inp);
    return 0;
}

bool _insert(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    node *current = root, *parent = NULL;

    if(root==NULL){
        root = temp;
        return 1;
    }
    else{
        while(1){

            parent = current;

            if(parent->data == data){
                return 0;
            }
            else if(data < current->data){
                current = parent->left;
                if(current==NULL){
                    parent->left = temp;
                    return 1;
                }
            }
            else if(data > current->data){
                current = parent->right;
                if(current==NULL){
                    parent->right = temp;
                    return 1;
                }
            }
        }
    }
}

void bst(node *ptr){
    if(ptr==NULL)
        return;
    bst(ptr->left);
    printf("%d  ", ptr->data);
    bst(ptr->right);
}
