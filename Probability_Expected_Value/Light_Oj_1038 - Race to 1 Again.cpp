#include<bits/stdc++.h>
using namespace std;

double dp[100010];
vector<int>v[100010];
int check()
{
    int count=0,a,b;
    for(int i=2;i<=100010;i++){
        count=0;
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                a=i/j;
                if(a!=j){
                    count+=2;
                    v[i].push_back(a);
                }
                else count++;
                v[i].push_back(j);
            }
        }
    }
}

int check2()
{
    dp[1]=0;
    int x,a,b,c;
    double sum=0;
    for(int i=2;i<=100005;i++){
        x=v[i].size();
        sum=1;
        for(int j=1;j<v[i].size();j++){
            a=v[i][j];
            b=i/a;
            sum+=(1+dp[b]);
        }
        sum=(sum)/(x-1);
       // cout<<i<<' '<<sum<<endl;
        dp[i]=sum;
    }
}
int main()
{
    check();
    check2();
    int t,n,x;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        scanf("%d",&n);
        printf("Case %d: %.09lf\n",cc,dp[n]);
    }
}
