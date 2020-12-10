#include<bits/stdc++.h>
using namespace std;

int ara[100],n;
int dp[55][5][5];

int optimal(int i,int c,int p)
{
    // cout<<i<<' '<<c<<' '<<p<<' '<<endl;
    if(i>n)return 0;
    if(dp[i][c][p]!=-1)return dp[i][c][p];
    int x;
    if(c==0){
        int xx=ara[i]+optimal(i+1,1,1);
        int yy=optimal(i+1,0,0);
        x=max(xx,yy);
    }
    else{
        int xx=optimal(i+1,0,1);
        int yy=ara[i]+optimal(i+1,1,0);
        x=min(xx,yy);
    }
    return dp[i][c][p]=x;

}

int main()
{
    int ss=0,xx;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        ss+=ara[i];
    }
    memset(dp,-1,sizeof dp);
    xx=optimal(1,0,0);
    cout<<ss-xx<<' '<<xx<<endl;

}
