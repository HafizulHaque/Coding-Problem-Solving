#include<bits/stdc++.h>
using namespace std;

long long ara[100010],ara1[100010],n,m,d;
#define lli 10000000010
long long cal(long long x)
{
    long long sum=0;
    for(int i=0;i<n;i++){
        if(abs(ara[i]-x)<=d)sum+=ara1[i];
    }
    cout<<x<<' '<<sum<<endl;
    return sum;
}
long long binary_S()
{
    long long l=0,h=lli,mid,x,mx=0;

    while(l<=h){
        mid=(l+h)/2;
        x=cal(mid);
        if(x>mx){
            mx=x;
            h=mid-1;
        }
        else l=mid+1;
    }
    cout<<mx<<endl;
}
int main()
{
    while(cin>>n>>d){
        for(int i=0;i<n;i++){
            cin>>ara[i]>>ara1[i];
        }
        binary_S();
    }
}
