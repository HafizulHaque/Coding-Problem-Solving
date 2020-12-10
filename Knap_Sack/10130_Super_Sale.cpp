#include<bits/stdc++.h>
using namespace std;

#define max_n 1010
#define max_w 40
int n;
int dp[max_n+1][max_w+1];
int weight[max_n+1],cost[max_n+1];

int func(int i,int w,int g)
{
    if(i==n+1)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    int profit1=0,profit2=0;

    if(w+weight[i]<=g)
        profit1=cost[i]+func(i+1,w+weight[i],g);

    profit2=func(i+1,w,g);
    dp[i][w]=max(profit1,profit2);
        return dp[i][w];
}

int main()
{
    int t;
    long value=0;
    scanf("%d",&t);
    while(t--){
        value=0;
        scanf("%d",&n);
        memset(cost,-1,sizeof(cost));
        memset(weight,-1,sizeof(weight));

        for(int i=1;i<=n;i++){
            scanf("%d%d",&cost[i],&weight[i]);
        }

        int h,g;
        scanf("%d",&h);

        for(int i=1;i<=h;i++){
            memset(dp,-1,sizeof(dp));
            scanf("%d",&g);
            value+=func(1,0,g);
        }
        cout<<value<<endl;
    }
}
