#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int ini, int fin){
    if(ini>=fin) return;
    int a = ini;
    int b = fin;
    int d;
    for(int i = 1; b>a; ++i){
        if(i&1){
            int key = arr[a];
            while(arr[b]>key) b--;
            if(a!=b) swap(arr[a], arr[b]);
            else d = a;
            a++;
        }
        else{
            int key = arr[b];
            while(arr[a]<key) a++;
            if(a!=b) swap(arr[a], arr[b]);
            else d = b;
            b--;
        }
    }
    cout << d << endl;
    quick_sort(arr, ini, d-1);
    quick_sort(arr, d+1, fin);
}

int main(){
    int arr[] = {2, 4, 1, 0, 3, 7, 4, 5, 3, 6};
    quick_sort(arr, 0, 9);
    for(int i = 0; i < 10; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
