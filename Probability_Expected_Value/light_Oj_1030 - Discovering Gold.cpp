#include<bits/stdc++.h>
using namespace std;

double dp[110],value[110];
int n;

int main()
{
    int t;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>value[i];
        }
        dp[n]=value[n];

        for(int i=n-1;i>=1;i--){
            double count=0,sum=0;
            for(int j=i+1;j<=i+6 and j<=n;j++){
                sum+=(dp[j]+value[i]);
                count++;
            }
           // cout<<sum<<' '<<count<<endl;
            if(count<6) sum=sum/count;
            else sum=sum/6;

            //cout<<i<<' '<<sum<<endl;
            dp[i]=sum;
        }
        printf("Case %d: %.09lf\n",cc,dp[1]);
    }
}
