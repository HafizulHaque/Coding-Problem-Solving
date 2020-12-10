#include<bits/stdc++.h>
using namespace std;

#define lli long long

lli upp(lli n,lli x)
{
    lli res=1,value=n;
    double s=1;
    for(lli i=1;i<=x;i++) res*=n;

    while(n>(value-x)){
        s*=double(n)/double(value);
        n--;
    }
    if(s<=0.5)return 1;
    else return 0;
}

int main()
{
    int t;
    cin>>t;

    for(int c=1;c<=t;c++){
        lli n;
        scanf("%lld",&n);
        lli x=1;
        for(x=1;x<=n;x++)
            if(upp(n,x))break;

        printf("Case %d: %lld\n",c,x-1);
    }
}
