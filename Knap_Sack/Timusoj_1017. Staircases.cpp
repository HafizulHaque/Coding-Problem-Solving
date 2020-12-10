#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define max_n 501
#define clean(a,b) memset(a,b,sizeof(a));
lli dp[max_n][max_n][32];
lli sum,n;
lli call(lli i,lli count,lli w)
{
    //cout<<i<<' '<<count<<' '<<w<<endl;
    if(i>=n+1){
        if(w==n&&count>1)
            return 1;
        else return 0;
    }
    if(dp[i][w][count]!=-1)return dp[i][w][count];
    lli profit1=0,profit2=0;
    if(w+i<=n)
        profit1=call(i+1,count+1,w+i);
        profit2=call(i+1,count,w);
    //cout<<i<<' '<<count<<' '<<w<<endl;
    return dp[i][w][count]=profit1+profit2;
}
int main()
{
    cin>>n;
    clean(dp,-1);
    cout<<call(1,0,0)<<endl;
}
