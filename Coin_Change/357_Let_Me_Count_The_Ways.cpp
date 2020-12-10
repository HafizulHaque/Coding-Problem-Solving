#include<bits/stdc++.h>
using namespace std;

int coin[]={1,5,10,25,50};
long long dp[6][30010];

long long call(int i,int amount)
{
    if(i>=5){
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
    while(cin>>n){
            a=call(0,n);
            if(a==1)
            printf("There is only 1 way to produce %lld cents change.\n",n);
            else
            printf("There are %lld ways to produce %lld cents change.\n",a,n);
        }
}


