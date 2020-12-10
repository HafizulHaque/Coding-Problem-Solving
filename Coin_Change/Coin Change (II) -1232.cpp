#include<bits/stdc++.h>
#define lli long long
#define mod 100000007
using namespace std;
int n, k;
#define max_n 104
#define max_w 10005
lli dp[max_w][max_n];
int coin[max_n];
void coin_change()
{
    int x, y;
    for(int i=0; i<n; i++) dp[0][i]=1;
    for(int i=1; i<k+1; i++){
            cout<<i<<' ';
        for(int j=0; j<n; j++){
            if(i>=coin[j]) x=dp[i-coin[j]][j];
            else x=0;
            if(j>=1) y=dp[i][j-1];
            else y=0;

        cout<<x<<' '<<y<<' ';
            dp[i][j]=(x+y)%mod;
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main()
{
    int t, kase=0;
    cin>>t;
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) scanf("%d", coin+i);
        coin_change();
        printf("Case %d: %lld\n", ++kase, dp[k][n-1]);
    }
    return 0;
}

