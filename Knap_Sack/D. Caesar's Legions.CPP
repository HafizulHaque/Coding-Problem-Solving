#include<bits/stdc++.h>
using namespace std;

int dp[105][105][13][13];
int n1,n2,k1,k2;

int call(int c1,int c2,int k3,int k4)
{
    //cout<<c1<<' '<<c2<<' '<<k3<<' '<<k4<<endl;
    if(c1+c2==n1+n2){
        return 1;
    }
    if(dp[c1][c2][k3][k4]!=-1)return dp[c1][c2][k3][k4];
    int profit1=0,profit2=0;
    if(k3+1<=k1&&c1+1<=n1)
        profit1=call(c1+1,c2,k3+1,0);
    if(k4+1<=k2&&c2+1<=n2)
        profit2=call(c1,c2+1,0,k4+1);
   // cout<<c1<<' '<<c2<<' '<<k3<<' '<<k4<<' ';
    //cout<<profit1<<' '<<profit2<<endl;
    return dp[c1][c2][k3][k4]=((profit1)%100000000+(profit2)%100000000)%100000000;

}
int main()
{
    while(cin>>n1>>n2>>k1>>k2){
        memset(dp,-1,sizeof(dp));
      cout<<call(0,0,0,0)<<endl;
    }
}
