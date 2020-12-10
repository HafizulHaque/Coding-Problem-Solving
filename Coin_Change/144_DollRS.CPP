#include<bits/stdc++.h>
using namespace std;

int coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[12][30010];

long long call(int i,int amount)
{
    if(i>=11){
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    long long ret1=0,ret2=0;
    if(amount-coin[i]>=0)ret1=call(i,amount-coin[i]);
    ret2=call(i+1,amount);
    return dp[i][amount]=ret1+ret2;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    long long a,b,n;
    while(scanf("%lld.%lld",&a,&b)){
            n=a*100+b;
        if(n==0)
            break;
        printf("%3lld.%.2lld%17lld\n",a,b,call(0,n));
    }
}

