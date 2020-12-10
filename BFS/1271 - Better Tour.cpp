#include<bits/stdc++.h>
using namespace std;
#define mm 50050
vector<int>z;
vector<int>edges[mm];
int ara[mm],ara1[mm];
int s,d;

int bfs(int src,int destiny)
{
    queue<int>q;
    q.push(src);
    int vis[mm],parent[mm];
    memset(vis,0,sizeof(vis));
    memset(parent,0,sizeof(parent));
    parent[src]=src;vis[src]=1;

    while(!q.empty()){
        int u=q.front();q.pop();

        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(vis[v]==0){
              if(v==destiny){
                parent[v]=u;
                vis[v]=1;
                while(!q.empty()){
                    q.pop();
                }
                break;
                }
                else{
                    parent[v]=u;
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }

    int v=destiny;
    while(1){
       // cout<<v<<endl;
        z.push_back(v);
        if(v==src)break;
        v=parent[v];
    }

}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
       int n,a,b;
       cin>>n;
       for(int i=1;i<=n;i++){
            cin>>ara[i];
       }

       for(int i=1;i<n;i++){
            a=ara[i],b=ara[i+1];
            edges[a].push_back(b);
            edges[b].push_back(a);
       }

       for(int i=1;i<=mm;i++){
            if(edges[i].size()==0)continue;
            sort(edges[i].begin(),edges[i].end());
       }
        s=ara[1],d=ara[n];
        //cout<<s<<' '<<d<<endl;
        bfs(s,d);
        printf("Case %d:\n",++cas);
        for(int i=z.size()-1;i>=0;i--){
            if(i==0)cout<<z[i]<<endl;
            else cout<<z[i]<<' ';
        }
        z.clear();
        for(int i=1;i<mm;i++)edges[i].clear();
    }
}
