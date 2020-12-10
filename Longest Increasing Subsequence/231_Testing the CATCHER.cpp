#include<bits/stdc++.h>
using namespace std;
int ara[10000];
int dp[10000];
int n;
#define clean(a,b) memset(a,b,sizeof(a))
int longest(int u,int n)
{
    if(dp[u]!=-1)return dp[u];
    int max=0,y;
    //cout<<ara[u]<<' '<<u<<endl;
    for(int v=u+1;v<=n;v++){
        if(ara[v]<ara[u]){
            y=longest(v,n);
            if(y>max)
                max=y;
        }
    }

    dp[u]=1+max;
    return dp[u];
}


int main()
{
    int cas=0,m;
    while(1){
        int i=1;
        cin>>m;
        if(m==-1)
            break;
        clean(dp,-1);
        if(cas>0)
            cout<<endl;
        ara[i]=m;
            i++;

        while(cin>>m){
            if(m==-1)
                break;
            ara[i]=m;
            i++;
        }
        i--;
        int max=0;

        for(int j=1;j<=i;j++){
            if(longest(j,i)>max)
                max=longest(j,i);
        }
        cout<<"Test #"<<++cas<<':'<<endl;
        printf("  maximum possible interceptions: %d\n",max);
    }
}

