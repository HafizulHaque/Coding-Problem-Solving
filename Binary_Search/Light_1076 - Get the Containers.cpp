#include<bits/stdc++.h>
using namespace std;
long long ara[1010],n,m;
#define ll 10000000000
long long cal(long long cap)
{
    long long ans=1,value=0;

    for(int i=0;i<n;i++){
        if(ara[i]>cap)return ll;
        if(value+ara[i]<=cap){
            value+=ara[i];
        }
        else{
            value=ara[i];
            ans++;
        }
    }
   // cout<<ans<<endl;
    return ans;
}

long long binary_S()
{
    long long high=ll,low=1,mid;

    while(low<=high)
    {
        mid=(low+high)/2;
       // cout<<low<<' '<<high<<' '<<mid<<endl;
        long long x=cal(mid);
        if(x<=m)high=mid-1;
        else low=mid+1;
    }
    //cout<<low<<endl;
    return low;

}
int main()
{
    long long t,cas=0;
    cin>>t;
    while(t--)
    {
        long long ma=0;
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<n;i++)scanf("%lld",&ara[i]);

        for(int i=0;i<n;i++)ma=max(ma,ara[i]);

        printf("Case %lld: ",++cas);
        if(m>=n){
            cout<<ma<<endl;
            continue;
        }
        cout<<binary_S()<<endl;

    }
}
