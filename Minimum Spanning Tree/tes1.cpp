#include<bits/stdc++.h>
using namespace std;

long long a,b,sum,n;

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<1<<endl;
        else cout<<n*(n-1)<<endl;
    }
}
