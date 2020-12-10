#include<bits/stdc++.h>
using namespace std;

#define max_n 110
#define max_w 510
int m;
int dp[max_n+1][max_w*max_n+1];
int cost[max_n+1];
int sum;

int func(int i,int w)
{
    if(i==m+1){
       int value=w;
       return abs(sum-2*value);
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int profit1=0,profit2=0;
    profit1=func(i+1,w+cost[i]);
    profit2=func(i+1,w);
    dp[i][w]=min(profit1,profit2);
    return dp[i][w];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&m);
    sum=0;
       for(int i=1;i<=m;i++){
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }
        printf("%d\n",func(1,0));
    }
}
