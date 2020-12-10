#include<bits/stdc++.h>
using namespace std;

#define mx 1000
#define clean(a,b) memset(a,b,sizeof(a))

int value[mx];
int dp[mx],dir[mx];
int n,count,g=0;

void solution(int start)
{
    while(start>=1)
    {
        printf("index %d value %d\n" ,start,value[start]);
        start=dir [start];
    }
}


int longest(int u)
{
    if(dp[u]!=-1){
        return dp[u];
    }
    int max=0;//count=0;
    cout<<value[u]<<' '<<u<<endl;

    for(int v=u+1;v<=n;v++)
    {
        if(value[v]>value[u])
        {
            int y=longest(v);
            if(y>max)
            {
                g++;
                max=y;
                dir[u]=v;
            }
        }
    }

     dp[u]=1+max;
    cout<<dp[u]<<' '<<u<<' '<<value[u]<<endl;
    return dp[u];
}

int main()
{
    clean(dp,-1);
    clean(dir,-1);
    int lis=0,start;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>value[i];

    for(int i=1;i<=n;i++)
    {
        printf("long path form %d: %d\n",value[i],longest(i));
        if(longest(i)>lis){
            lis=longest(i);
            start=i;
        }
    }
    cout<<g<<endl;
    printf("LIS = %d Starting point %d\n",lis,start);
    solution(start);
}
