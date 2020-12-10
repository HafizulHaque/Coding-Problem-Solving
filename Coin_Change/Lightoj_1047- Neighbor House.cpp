#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define max_n 23
#define inf INFINITY
#define clean(a,b) memset(a,b,sizeof(a))
int mat[max_n][5];
int dp[max_n][5];
int r;
int call(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    int ret=inf;
    if(i>r)return 0;
    //cout<<i<<' '<<j<<' '<<endl;
    if(j==1){
        ret=min(ret,call(i+1,j+1)+mat[i][j]);
        //cout<<i<<' '<<j<<' '<<ret<<endl;
        ret=min(ret,call(i+1,j+2)+mat[i][j]);
        //cout<<i<<' '<<j<<' '<<ret<<endl;
        return dp[i][j]=ret;
    }
    else if(j==2){
       ret=min(ret,call(i+1,j-1)+mat[i][j]);
        //cout<<i<<' '<<j<<' '<<ret<<endl;
        ret=min(ret,call(i+1,j+1)+mat[i][j]);
        // cout<<i<<' '<<j<<' '<<ret<<endl;
        return dp[i][j]=ret;
    }
    else{
        ret=min(ret,call(i+1,j-1)+mat[i][j]);
         //cout<<i<<' '<<j<<' '<<ret<<endl;
        ret=min(ret,call(i+1,j-2)+mat[i][j]);
         //cout<<i<<' '<<j<<' '<<ret<<endl;
       return dp[i][j]=ret;
    }
}
int main()
{
    int t,caseno=0,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>r;
        clean(dp,-1);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=3;j++)
                cin>>mat[i][j];
        }
        a=call(1,1);b=call(1,2);c=call(1,3);
        //cout<<a<<' '<<b<<' '<<c<<endl;
        printf("Case %d: %d\n",++caseno,min(a,min(b,c)));
    }
}
