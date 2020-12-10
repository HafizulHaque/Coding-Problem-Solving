#include<bits/stdc++.h>
using namespace std;

long long ara[100010],m,n;
#define ll 1000000000010

long long find_V(long long k)
{
    long long a=1,in=0;
    for(int i=0;i<n;i++){
        if(ara[i]-in>k){
            return 0;
        }
        else if(ara[i]-in==k){
            in=ara[i];
            k--;
        }
        else in=ara[i];
    }
    return 1;
}

long long binary_S()
{
    long long high=ll,low=1,mid;

    while(low<=high)
    {
        mid=(low+high)/2;
        long long x=find_V(mid);
        if(x==0)low=mid+1;
        else high=mid-1;
    }
   // cout<<low<<endl;
    return low;
}

int main()
{
    long long t,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)scanf("%lld",&ara[i]);

        printf("Case %lld: ",++cas);
        cout<<binary_S()<<endl;
    }
}
