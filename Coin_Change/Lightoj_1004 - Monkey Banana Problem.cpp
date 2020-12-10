#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define max_n 210
#define clean(a,b) memset(a,b,sizeof(a))
lli mat[max_n][max_n];
lli dp[max_n][max_n];
lli n,sum;
lli rock(lli i,lli j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i>=1&&i<n and j>=1&&j<=i){
        lli ret=-INFINITY;
        ret=max(ret,rock(i+1,j)+mat[i][j]);
        ret=max(ret,rock(i+1,j+1)+mat[i][j]);
        return dp[i][j]=ret;
    }
    else if(i>=n&&i<2*n and j>=1&&j<=2*n-i){
        lli ret=-INFINITY;
        ret=max(ret,rock(i+1,j-1)+mat[i][j]);
        ret=max(ret,rock(i+1,j)+mat[i][j]);
        return dp[i][j]=ret;
    }
    else return 0;
}

int main()
{
    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
        clean(dp,-1);
        scanf("%lld",&n);
        for(lli i=1;i<=2*n-1;i++){
            if(i<n){
                for(lli j=1;j<=i;j++)
                    scanf("%lld",&mat[i][j]);
            }
            else{
                for(lli j=1;j<=2*n-i;j++)
                 scanf("%lld",&mat[i][j]);
            }
        }
        sum=rock(1,1);
        printf("Case %d: %lld\n",++caseno,sum);
    }

}
