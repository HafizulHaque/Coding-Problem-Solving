#include<bits/stdc++.h>
using namespace std;

#define inf 1e9
#define mx 100010
int dp[mx],ara[mx],n;

int longest()
{
    dp[0]=-inf;
    for(int i=1;i<=n;i++)dp[i]=inf;

    int Lislength=0;

    for(int i=1;i<=n;i++){
        int low=0,high=Lislength,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(dp[mid]<ara[i])
                low=mid+1;
            else high=mid-1;
        }
        dp[low]=ara[i];
        Lislength=max(Lislength,low);
    }
    cout<<Lislength<<endl;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ara[i];
    longest();
}

