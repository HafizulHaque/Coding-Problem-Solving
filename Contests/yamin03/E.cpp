// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n, evenOdd = 0, oddEven = 0, evenEven = 0, oddOdd = 0;
    int a, b, totalA = 0, totalB = 0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a%2==0&&b%2==0) evenEven++;
        else if(a%2==1&&b%2==0) oddEven++;
        else if(a%2==0&&b%2==1) evenOdd++;
        else if(a%2==1&&b%2==1) oddOdd++;
        totalA += a;
        totalB += b;
    }
    if(totalA%2==0&&totalB%2==0){
        cout << 0 << endl;
    }
    else if(totalA%2==1&&totalB%2==1){
        if(evenOdd>=1||oddEven>=1) cout << 1 << endl;
        else cout << -1 << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}
