#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, temp;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; ++i)
        cin>> arr[i];

    int _count = 0;
    for(int i = 0; i <= n-1; ++i){
        for(int j = n-1; j >= i+1; --j){
            if(arr[j]<arr[j-1]){
                _count++;
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl << _count << endl;
    return 0;
}
