#include<bits/stdc++.h>
using namespace std;

#define mx 1010
#define clean(a,b) memset(a,b,sizeof(a))
#define cin(n) cin>>n
int dp[35][mx];
int d[35],v[35];
int dir[35][mx];
int tim,w,value,n;
int cuu(int i,int t,int y)
{
    if(dir[i][t]==-1){
        cout<<y<<endl;
            return 0;
    }
    if(dir[i][t]==1 and t-3*w*d[i]>=0){
       cuu(i+1,t-3*w*d[i],y+1);
    }
    else{
        cuu(i+1,t,y);
    }

}

int solution(int i,int t)
{
    if(dir[i][t]==-1||t<=0||i>=n+1){
            return 0;
    }
    if(dir[i][t]==1 and t-3*w*d[i]>=0){
       cout<<d[i]<<' '<<v[i]<<endl;
       solution(i+1,t-3*w*d[i]);
    }
    else{
        solution(i+1,t);
    }
}
int call(int i,int t)
{
     //cout<<i<<' '<<t<<' '<<weight<<endl;
    if (dp[i][t]!=-1)return dp[i][t];
    if(i>=n+1){
        return 0;
    }
    int profit1=0,profit2=0;
    if(t-3*w*d[i]>=0){
        profit1=v[i]+call(i+1,t-3*w*d[i]);
    }
    profit2=call(i+1,t);
    //cout<<i<<' '<<t<<' '<<profit1<<' '<<profit2<<endl;
    if(profit1>=profit2){
        dir[i][t]=1;
        return dp[i][t]=profit1;
    }
    else{
        dir[i][t]=2;
        return dp[i][t]=profit2;
    }
}
int main()
{
    int g=1;
   while(cin>>tim>>w)
   {
       if(g++>1)
        cout<<endl;
       clean(dp,-1);
       clean(dir,-1);
       cin>>n;
       for(int i=1;i<=n;i++)
        cin>>d[i]>>v[i];
        int r=call(1,tim);
        if(r==0){
            cout<<0<<endl;
            cout<<0<<endl;
        }
        else{
            cout<<r<<endl;
            cuu(1,tim,0);
            solution(1,tim);
        }
   }
}

