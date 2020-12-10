#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    int n;
    while(cin>>n){
        cout << (n*n+n)/2-2*(n-1) << endl;
    }

    return 0;
}
