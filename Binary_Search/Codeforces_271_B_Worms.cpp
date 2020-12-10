#include<bits/stdc++.h>
using namespace std;

long long ara[100010],n,m,x;

long long binary_S(long long l,long long h,long long v)
{
    long long mid,ans;

    while(l<=h){
        mid=(l+h)/2;
        //cout<<l<<' '<<h<<' '<<mid<<endl;
        if(ara[mid]>=v)h=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
    return l;
}

int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++){
            cin>>m;
            ara[i]=m+ara[i-1];
        }
        cin>>m;
        while(m--){
            cin>>x;
            binary_S(1,n,x);
        }
    }
}
