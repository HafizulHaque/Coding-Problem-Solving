#include<bits/stdc++.h>
using namespace std;
#define lli long long
lli n;
lli play(lli a)
{
    for(int i=2;i<=9;i++){
        if(i==a)return 1;
    }
    int flag=1;
    for(int i=2;i<=9;i++){
        if(play((a/i)+(a%i))==0)flag=0;
    }
    if(flag==0 )return 1;
    return 0;
}
int main()
{
    lli n;

    while(cin>>n){
        for(int i=2;i<=n;i++){
            int x=play(i);
            cout<<i<<' '<<x<<endl;
            if(x==1)cout<<"Stan wins."<<endl;
            else cout<<"Ollie wins."<<endl;
        }
    }
}
