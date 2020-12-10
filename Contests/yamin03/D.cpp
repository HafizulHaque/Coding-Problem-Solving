// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin>>n>>k;
    vector<vector<ll> > dp(1+k, vector<ll>(1+n, 0));
    for(ll last = 1; last <= n; last++) dp[1][last] = 1;
    for(ll length = 2; length <= k; length++){
        for(ll div = 1; div <= n; div++){
            for(ll last = div; last <= n; last += div){
                dp[length][last] += dp[length-1][div];
                dp[length][last] %= MOD;
            }
        }
    }
    ll total = 0;
    for(ll last = 1; last <= n; last++){
        total += dp[k][last];
        total %= MOD;
    }
    cout << total << endl;
    return 0;
}
