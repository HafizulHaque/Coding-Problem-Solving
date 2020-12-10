#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define sc(x) scanf("%d",&x);
int ara[mx],tree[3*mx],n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        sc(ara[i]);
    int v=0,ans=0;
    for(int i=1;i<=n;i++){
        if(ara[i]!=v){
            ans++;
            v=ara[i];
        }
    }
    cout<<ans<<endl;
}

