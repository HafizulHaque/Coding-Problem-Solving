#include<bits/stdc++.h>
using namespace std;
int ara[65];

int grundy()
{
    int x;
    for(int i=1;i<=60;i++){
        x=((-1+double(sqrt(1+8*i)))/2);
        ara[i]=x;
    }
}

int main()
{
    int n,x;
    grundy();
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++){
        cin>>x;
        k^=ara[x];
    }
    if(k>0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
