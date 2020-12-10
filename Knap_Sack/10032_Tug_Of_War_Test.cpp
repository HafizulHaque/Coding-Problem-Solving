#include<bits/stdc++.h>
using namespace std;
#define max_n 51
#define max_w 451
int m;
int dp[max_n+1][max_w*51+1];
int cost[101+1];
int sum,value;
int func(int i,int w,int count)
{
    //cout<<i<<' '<<w<<' '<<count<<endl;
    if(i==m+1&&count<value){
            return -1;
    }
    if(count==value){
          int v=w;
       return abs(sum-2*v);
    }

    if(dp[count][w]!=-1)return dp[count][w];
    int profit1=0,profit2=0;
    if(count+1<=value)
    profit1=func(i+1,w+cost[i],count+1);
    profit2=func(i+1,w,count);
    //cout<<i<<' '<<w<<' '<<profit1<<' '<<profit2<<endl;
    if(profit1==-1){
        dp[count][w]=profit2;
    }
    else if(profit2==-1){
        dp[count][w]=profit1;
    }
    else
        dp[count][w]=min(profit1,profit2);
    return dp[count][w];
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--){
     memset(dp,-1,sizeof(dp));
     scanf("%d",&m);
     sum=0,value=(m+1)/2;
       for(int i=1;i<=m;i++){
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }
        int d=sum+func(1,0,0);
        int a=(d)/2;
        int b=sum-a;
        printf("%d %d\n",min(a,b),max(a,b));
        if(t!=0)
            cout<<endl;
    }
}

