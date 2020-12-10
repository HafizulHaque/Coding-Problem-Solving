#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("dp002.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, s, x;
    cin>>n>>s;
    int val[n+1], sol[s+1], track[s+1];
    for(int i = 1; i <= n; ++i) cin>>val[i];
    //algorithm
    sol[0] = 0,track[0] = 0;
    for(int i = 1; i <= s; ++i) sol[i] = INT_MAX-1;
    sort(val+1, val+(n+1));
    x = s/val[1];
    for(int i = 1; i <= n; ++i){
        x--;
        for(int j = 0; j <= s; ++j){
            if(sol[j]!=INT_MAX-1&&j+val[i]<=s&&sol[j+val[i]]<sol[j]+1){
                sol[j+val[i]] = sol[j]+1;
                track[j+val[i]] = j;

            }
        }
        if(!x) break;
    }

}
