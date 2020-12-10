#include<bits/stdc++.h>
using namespace std;

int n;
double cap,wght[110],cost[110];
int ara[110][10010];

double optimal(int i,int w)
{
    if(i>n)return 0;
    if(ara[i][w]!=-1)return ara[i][w];
    int profit1=0,profit2=0;
    long double a=(1.0-(double(w)/10000.0))*(1.0-cost[i]);
    a=(1.0-a)*10000;
    int x=floor(a);
  //  cout<<x<<endl;
    if(x<cap){
        profit1=wght[i]+optimal(i+1,x);
    }
    profit2=optimal(i+1,w);
    //cout<<i<<' '<<profit1<<' '<<profit2<<endl;
    return ara[i][w]=max(profit1,profit2);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int c=1;c<=t;c++){
      scanf("%lf %d",&cap,&n);

     memset(ara,-1,sizeof(ara));
      cap*=10000;
      for(int i=1;i<=n;i++){
        scanf("%lf %lf",&wght[i],&cost[i]);
      }
      int x=optimal(1 ,1);
      printf("Case %d: %d\n",c,x);
    }
}
