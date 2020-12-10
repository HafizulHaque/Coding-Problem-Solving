#include<bits/stdc++.h>
using namespace std;
#define max_n 104
#define max_w 10010
#define pii pair<int,int>
int m;
pii dp[max_n+1][max_n+1];
int cost[103+1];
int sum,value,make,g;
pii func(int i,int w,int count)
{
   // cout<<i<<' '<<w<<' '<<count<<endl;
    if(i>=g+1){
            if(w>=make)
                return make_pair(abs(w-make),count);
            else
                return make_pair(-1,-1);
    }
    if(dp[i][count].first!=-1&&dp[i][count].second!=-1)return dp[i][count];
    if(w>=make){
        return make_pair(abs(w-make),count);
    }
    pii profit1(0,count),profit2(0,count);
    if(count+1<=g)
    profit1=func(i+1,w+cost[i],count+1);

    profit2=func(i+1,w,count);
    //cout<<i<<' '<<w<<' '<<profit1.first<<' '<<profit2.first<<endl;
    if(profit1.first==-1){
        dp[i][count]=profit2;
    }
    else if(profit2.first==-1){
        dp[i][count]=profit1;
    }
    else if(profit1.first==profit2.first){
        dp[i][count].first=profit1.first;
        dp[i][count].second=min(profit1.second,profit2.second);
    }
    else{
            if(profit1.first<profit2.first)
                dp[i][count]=profit1;
            else
                  dp[i][count]=profit2;
    }
    return dp[i][count];
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--){
     memset(dp,-1,sizeof(dp));
     scanf("%d",&make);
     cin>>g;
     for(int i=1;i<=g;i++)
        cin>>cost[i];
        pii a=func(1,0,0);
     cout<<a.first+make<<' '<<a.second<<endl;;
    }
}

