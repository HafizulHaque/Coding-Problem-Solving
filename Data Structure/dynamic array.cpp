#include <bits/stdc++.h>
using namespace std;

int arr_size;
int *arr, *temp_arr;

void print(){
    cout << "elements are :" << endl;
    for(int i = 0; i < arr_size; ++i){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void insertBackElement(){
    int n;
    cout << "How many elements do you want to insert : ";
    cin>>n;
    int prev_size = arr_size;
    arr_size += n;
    arr = (int *)realloc(arr, arr_size*sizeof(int));

    cout << "Enter " << n << " elements value : ";
    for(int i = prev_size; i < arr_size; ++i){
        cin>>arr[i];
    }
    print();
}

void deleteElement(){
    int n;
    cout << "How many elements do you want to delete : ";
    cin>>n;
    arr_size -= n;
    arr = (int *)realloc(arr, arr_size*sizeof(int));
    print();
}

int main(){

    //declare initial size of array and also initialize the values
    printf("input initial size of array: ");
    scanf("%d", &arr_size);
    arr = (int *)malloc(arr_size*sizeof(int));
    printf("initialize values of the array: ");
    for(int i = 0; i < arr_size; ++i){
        cin>>arr[i];
    }
    print();

    breakPoint:
    int chooseOption;
    cout << "Enter 0 to exit, 1 to delete element, Enter 2 to insert back element...  ";
    cin>>chooseOption;
    if(chooseOption==0){
        goto endPoint;
    }
    else if(chooseOption==1){
        deleteElement();
    }
    else if(chooseOption==2){
        insertBackElement();
    }
    goto breakPoint;
    endPoint:
    free(arr);
    return 0;
}
