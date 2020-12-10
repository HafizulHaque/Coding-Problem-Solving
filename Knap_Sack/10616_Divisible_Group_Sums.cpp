#include<bits/stdc++.h>
using namespace std;
#define max_n 210
#define max_w 15
#define ll long long int
ll m;
ll dp[max_n+1][max_n+1][13];
ll cost[max_n+1];
ll sum,n,q;
ll func(ll i,ll s,ll count,ll a,ll b)
{
    //cout<<i<<' '<<s<<' '<<count<<endl;//' '<<a<<' '<<b<<endl;
     if(i>n+1){
       return 0;
    }
    if(count==b){
        if(s%a==0){
           // cout<<s<<' '<<a<<endl;
            return 1;
        }
        else
            return 0;
    }
    ll h,profit1=0,profit2=0;
    if(dp[i][s][count]!=-1)return dp[i][s][count];
    if(cost[i]<0)
        h=((cost[i]*(-1)*a)+(cost[i]))%a;
    else
        h=cost[i]%a;
        //cout<<h<<endl;
    //cout<<s<<' '<<h<<' '<<s+h<<endl;
    if(count+1<=b)
        profit1=func(i+1,(s+h),count+1,a,b);
    profit2=func(i+1,s,count,a,b);
    //cout<<i<<' '<<s<<' '<<count<<' '<<profit1<<' '<<profit2<<endl;
    //cout<<profit1<<' '<<profit2<<endl;
    dp[i][s][count]=profit1+profit2;
    return dp[i][s][count];
}
int main()
{
    ll t=1;
    while(cin>>n>>q){
        if(n==0&&q==0)
            break;
        for(ll i=1;i<=n;i++)
            cin>>cost[i];
        ll a,b;
        printf("SET %d:\n",t);
        for(ll i=1;i<=q;i++){
            memset(dp,-1,sizeof(dp));
            cin>>a>>b;
            printf("QUERY %d: ",i);
            cout<<func(1,0,0,a,b)<<endl;
        }
    t++;
    }
}
