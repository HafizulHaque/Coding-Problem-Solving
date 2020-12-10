#include<bits/stdc++.h>
using namespace std;
int dp[110];
int play(int n)
{
    if(dp[n]!=-1)return dp[n];
    if(n==0 or n==1)return dp[n]=0;
    if(n>=2 and play(n-2)==0)return dp[n]=1;
    if(n>=3 and play(n-3)==0)return dp[n]=1;
    if(n>=5 and play(n-5)==0)return dp[n]=1;
    return dp[n]=0;
}
int main()
{
    int n,p,t;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>t;
        p=play(t);
        if(p==1)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }

}
