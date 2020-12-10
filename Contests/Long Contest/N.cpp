//accepted

#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node *left;
    node *right;
};
node *root;

void insertItem(int item){
    node *temp = new node();
    temp->left = NULL;
    temp->right = NULL;
    temp->data = item;
    if(root==NULL){
         root = temp;
         return;
    }
    node *current = root;
    while(current!=NULL){
        if(item>current->data){
            if(current->right==NULL){
                current->right = temp;
                return;
            }
            current = current->right;
        }
        else if(item<current->data){
            if(current->left==NULL){
                current->left = temp;
                return;
            }
            current = current->left;
        }
    }
    return;
}
void traverseRightLeftParent(node *temp){
    if(temp==NULL) return;
    if(temp->right!=NULL) traverseRightLeftParent(temp->right);
    if(temp->left!=NULL) traverseRightLeftParent(temp->left);
    cout << temp->data << endl;
}

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin>> arr[i];
    for(int i = n-1; i >= 0; --i){
        insertItem(arr[i]);
    }
    traverseRightLeftParent(root);
    //fclose(inp);
    return 0;
}
