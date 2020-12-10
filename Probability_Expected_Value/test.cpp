#include<bits/stdc++.h>
using namespace std;

int n;
double cap,wght[110],cost[110];
int ara[110][10010];

double optimal(int i,int sum,double c)
{
    if(i>n)return 0;
    if(ara[i][sum]!=-1)return ara[i][sum];
    int profit1=0,profit2=0;
   // cout<<i<<' '<<sum<<' '<<c<<endl;
    double x=1-((1-c)*(1-cost[i]));
   // cout<<i<<' '<<x<<endl;
    if(x<cap){
        profit1=wght[i]+optimal(i+1,sum+wght[i],x);
    }
    profit2=optimal(i+1,sum,c);
    //cout<<endl;
   // cout<<i<<' '<<profit1<<' '<<profit2<<endl;
    return ara[i][sum]=max(profit1,profit2);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int c=1;c<=t;c++){
      scanf("%lf %d",&cap,&n);

     memset(ara,-1,sizeof(ara));
      for(int i=1;i<=n;i++){
        scanf("%lf %lf",&wght[i],&cost[i]);
      }
      int x=optimal(1,0,.0000000009);
      printf("Case %d: %d\n",c,x);
    }
}
