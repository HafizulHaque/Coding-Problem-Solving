#include<bits/stdc++.h>
using namespace std;

#define max_n 100
#define max_w 1000
int n;
int dp[max_n+1][max_w+1];
int weight[max_n+1],cost[max_n+1];
int cap;

int func(int i,int w)
{
    if(i==n+1)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    int profit1=0,profit2=0;

    if(w+weight[i]<=cap)
        profit1=cost[i]+func(i+1,w+weight[i]);

    profit2=func(i+1,w);
    dp[i][w]=max(profit1,profit2);
        return dp[i][w];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&cap);

    for(int i=1;i<=n;i++){
        scanf("%d%d",&weight[i],&cost[i]);
    }

    printf("%d\n",func(1,0));
}
