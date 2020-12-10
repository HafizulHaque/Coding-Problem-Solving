#include<bits/stdc++.h>
using namespace std;

int dp[105][1010];
int dir[105][1010];
int ara[210];
int n,m,sum,i,j,k,a;
int solution(int i,int sum1,int sum2)
{
    if(dir[i][sum1]==-1){
            return 0;
    }
    if(dir[i][sum1]==1 and sum1-ara[i]>=0){
       cout<<"port"<<endl;
       solution(i+1,sum1-ara[i],sum2);
    }
    if(dir[i][sum1]==2){
        cout<<"starboard"<<endl;
        solution(i+1,sum1,sum2-ara[i]);
    }
}

int call(int i,int sum1,int sum2)
{
    if(dp[i][sum1]!=-1)return dp[i][sum1];
    if(i>=a+1)
        return 0;
    int profit1=0,profit2=0;
  //  cout<<i<<' '<<sum1<<' '<<sum2<<' '<<c1<<' '<<c2<<endl;

    if(sum1-ara[i]>=0)
        profit1=1+call(i+1,sum1-ara[i],sum2);
    if(sum2-ara[i]>=0)
        profit2=1+call(i+1,sum1,sum2-ara[i]);
    //cout<<profit1<<' '<<profit2<<endl;
    if(profit1>=profit2){
        dir[i][sum1]=1;
        cout<<i<<' '<<sum1<<endl;
        return dp[i][sum1]=profit1;
    }
    else{
        dir[i][sum1]=2;
         cout<<i<<' '<<sum1<<endl;
        return dp[i][sum1]=profit2;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dir,-1,sizeof(dir));
        memset(dp,-1,sizeof(dp));
        cin>>n;
        n=n*100;
        a=1;
        while(cin>>m){
            if(m==0)
            break;
            if(a<=200){
                ara[a]=m;
                a++;
            }
        }
        a--;
        cout<<call(1,n,n)<<endl;
        solution(1,n,n);
    }
}
