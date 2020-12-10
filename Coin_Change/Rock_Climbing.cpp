#include<bits/stdc++.h>
using namespace std;
int mat[10][10];
int dp[10][10];
int r,c;
int rock(int i,int j)
{
    if(i>=0&&i<r and j>=0&&j<c)
    {
        if(dp[i][j]!=-1)return dp[i][j];
        int ret=-INFINITY;
        ret=max(ret,rock(i+1,j)+mat[i][j]);
        ret=max(ret,rock(i+1,j-1)+mat[i][j]);
        ret=max(ret,rock(i+1,j+1)+mat[i][j]);
        return dp[i][j]=ret;
    }
    else{
        return 0;
    }
}

int main()
{
    while(cin>>r>>c)
    {
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cin>>mat[i][j];
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",rock(0,0));
    }
}
