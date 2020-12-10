#include<bits/stdc++.h>
using namespace std;
#define max_n 55
#define ll long long int
ll m;
ll dp[max_n+1][22+1][1010];
ll cost[max_n+1];
ll number[max_n+1];
ll sum,n,q,make;
ll func(ll i,ll count,ll s)
{
    //cout<<i<<' '<<count<<' '<<s<<endl;
     if(i>=n+1){
            if(s==make)
            return 1;
        else
            return 0;
    }
    ll h,profit1=0,profit2=0;
    if(dp[i][count][s]!=-1)return dp[i][count][s];
    if(count+1<=number[i]&&s+cost[i]<=make)
    profit1=func(i,count+1,s+cost[i]);
     profit2=func(i+1,0,s);
    //cout<<i<<' '<<s<<' '<<count<<' '<<profit1<<' '<<profit2<<endl;
    dp[i][count][s]=((profit1)%100000007+(profit2)%100000007)%100000007;
    return dp[i][count][s];
}
int main()
{
    ll t=1,caseno=0;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n>>make;
        for(ll i=1;i<=n;i++)
            cin>>cost[i];
        for(ll i=1;i<=n;i++)
            cin>>number[i];
        printf("Case %lld: %lld\n",++caseno,func(1,0,0));
    }
}
