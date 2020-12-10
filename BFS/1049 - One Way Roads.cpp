#include<bits/stdc++.h>
using namespace std;

int lef[110],righ[110];

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        int n,u,v,c,wl,wr;
        cin>>n;
        wl=0,wr=0;

        memset(lef,0,sizeof(lef));
        memset(righ,0,sizeof(righ));

        for(int i=1;i<=n;i++){
            cin>>u>>v>>c;
            if(!lef[u] and !righ[v]){
                lef[u]=1;
                righ[v]=1;
                wl+=c;
            }
            else{
                righ[u]=1;
                lef[v]=1;
                wr+=c;
            }
        }
       // cout<<wl<<' '<<wr<<endl;

        printf("Case %d: %d\n",++cas,min(wr,wl));
    }
}
