#include<bits/stdc++.h>
using namespace std;
#define max_n 25
#define max_w 210
int m;
int dp[max_n+1][max_w+1];
int cost[max_n+1];
int sum,value,j;
int func(int i,int w)
{
   // cout<<i<<' '<<w<<endl;
    if(i==j){
        return abs(sum-2*w);
    }
    if(dp[i][w]!=-1)return dp[i][w];

    int profit1=0,profit2=0;

    profit1=func(i+1,w+cost[i]);
    profit2=func(i+1,w);
    //cout<<i<<' '<<w<<' '<<profit1<<' '<<profit2<<endl;
    dp[i][w]=min(profit1,profit2);
    return dp[i][w];
}
int main()
{
    int t;
    string s;
    cin>>t;
    getchar();
    while(t--)
    {
         memset(dp,-1,sizeof(dp));
        //getchar();
        getline(cin,s);
        j=1,sum=0;
        for(int i=s.length()-1;i>=0;){
            int a=1,value=0;
            while(i>=0){
                if(s[i]==' '){
                    i--;
                    break;
                }
                value+=(s[i]-'0')*a;
                a=a*10;
                i--;
            }
            sum+=value;
            cost[j]=value;
            j++;
        }
        int a=func(1,0);
        //cout<<a<<endl;
        if(a==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
