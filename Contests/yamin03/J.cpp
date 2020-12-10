// accepted

#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n, num, _max, temp;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>num;
        arr[i] = arr[i-1];
        if(num&1) arr[i]++;
    }
    _max = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            temp = arr[i-1]+arr[n]-arr[j];
            temp += ((j-arr[j])-((i-1)-arr[i-1]));
            if(temp>_max) _max = temp;
        }
    }
    cout << _max << endl;
    return 0;
}
