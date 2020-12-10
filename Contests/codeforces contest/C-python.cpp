#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000007

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    int n, forCount = 0;
    ll ans = 1;
    scanf("%d\n", &n);
    char statments[n];
    for(int i = 0; i < n; ++i) cin>>statments[i];
    if(statments[0]=='f') forCount = 1;
    for(int i = 1; i < n; ++i){
        if(statments[i]=='f'){
            forCount++;
            if(statments[i-1]=='f');//do nothing
            // do nothing
            else if(statments[i-1]=='s') ans = (ans*(forCount+1)%N)%N;
        }
        else if(statments[i]=='s'){
            if(statments[i-1]=='f');//do nothing
            else if(statments[i-1]=='s') ans = (ans*(forCount+1)%N)%N;
        }
    }
    cout << ans << endl;
    return 0;
}
