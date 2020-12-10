// problem Definition:
// Given n coins valued v1,v2,v3,....,vn using any number of these coins
// we have to gather minimum number of coin/s to make the sum equal to S

#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("dp001.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, s;
    cin>>n>>s;
    int val[n+1], sol[s+1], track[s+1];
    for(int i = 1; i <= n; ++i) cin>>val[i];
    //algorithm
    for(int i = 1; i <= s; ++i) sol[i] = INT_MAX-1;
    sol[0] = 0, track[0] = 0;
    for(int i = 1; i <= s; ++i){
        for(int j = 1; j <= n; ++j){
            if(val[j]<=i&&sol[i-val[j]]+1<sol[i]){
                sol[i] = sol[i-val[j]]+1;
                track[i] = i-val[j];
            }
        }
    }
    if(sol[s]!=INT_MAX-1){
        cout << "Count of min Coin : " << sol[s] << endl;
        cout << "Coins are :" << endl;
        int coins = s;
        while(coins){       // code for getting coin combination
            cout << coins-track[coins] << " ";
            coins = track[coins];
        }
        cout << endl;
    }
    else cout << "No solution available." << endl;
    return 0;
}


