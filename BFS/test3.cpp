#include<bits/stdc++.h>
using namespace std;

#define pii pair<long,long>
#define mm 3000010
long ara[mm];
int vis[mm];
vector<pii>v;
vector<long>v1;

int main()
{
    int n;
    while(cin>>n){

        for(int i=1;i<=n;i++){
            cin>>ara[i];
        }

        memset(vis,0,sizeof(vis));
        int c=1;

        for(int i=1;i<=n;i++){
            if(vis[ara[i]]==1){
                v.push_back(pii(c,i));
                for(int j=0;j<v1.size();j++){
                    long x=v1[j];
                    vis[x]=0;
                }
                c=i+1;
                v1.clear();
            }
            else {
                vis[ara[i]]=1;
                v1.push_back(ara[i]);
            }
        }

         if(v.size()==0)cout<<-1<<endl;
         else{
            cout<<v.size()<<endl;
            if(c<=n){
                long x=v.size();
                v[x-1].second=n;
            }
            for(int i=0;i<v.size();i++){
                long  x=v[i].first;
                long y=v[i].second;
               cout<<x<<' '<<y<<endl;
            }
         }
        v.clear();
    }
}
