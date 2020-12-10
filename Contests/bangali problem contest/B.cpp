// accepted

#include<bits/stdc++.h>
using namespace std;
#define i64 unsigned long long
#define N 1000000007
int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int t;
    i64 num;
    cin>>t;
    while(t--){
        cin>>num;
        num %= N;
        if(!num) cout << 1 << endl;
        else cout << num << endl;
    }
    return 0;
}
