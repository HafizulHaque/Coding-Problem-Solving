#include<bits/stdc++.h>
using namespace std;

int coin[25];
long long dp[25][10000];
int make;
int coin1()
{
    int j=1;
    for(int i=0;i<21;i++){
        coin[i]=j*j*j;
      //cout<<coin[i]<<endl;
        j++;
    }
}

long long call(int i,int amount)
{
    if(i>=21){
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
    coin1();
    memset(dp,-1,sizeof(dp));
    while(cin>>make){
        cout<<call(0,make)<<endl;
    }
}

