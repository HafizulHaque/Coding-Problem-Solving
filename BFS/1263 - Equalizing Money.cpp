#include<bits/stdc++.h>
using namespace std;
#define mm 1010

vector<int>edges[mm];
int ara[mm];
int value;

int bfs(int src,int dv)
{
    queue<int>q;
    q.push(src);
    int vis[mm];
    memset(vis,0,sizeof(vis));

    while(!q.empty()){
        int u=q.front();q.pop();

        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(vis[v]==0){
                if(ara[v]<value){
                       // cout<<v<<' '<<ara[v]<<endl;
                    ara[v]+=dv;
                    if(ara[v]>value){
                        dv=ara[v]-value;
                        ara[v]=value;
                    }
                    else{
                        dv=0;
                        while(!q.empty()){
                                q.pop();
                        }
                        break;
                    }
                }
                   vis[v]=1;
                   q.push(v);
            }
        }
    }
    return dv;
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        int n,m,u,v,sum=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
            sum+=ara[i];
        }

        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        if((sum%n)!=0){
            printf("Case %d: No\n",++cas);
        }
        else{
           value=sum/n;
          // cout<<value<<endl;
           for(int i=1;i<=n;i++){
                if(ara[i]>value){
                    int x=ara[i]-value;
                    ara[i]=value;
                    //cout<<ara[i]<<endl;
                    int y=bfs(i,x);
                    //cout<<y<<' '<<'m'<<endl;
                    ara[i]+=y;
                }
           }
           int flag=0;

           for(int i=1;i<=n;i++){
                //cout<<ara[i]<<endl;
                if(ara[i]!=value){
                    flag=1;
                    break;
                }
           }
           if(flag==1) printf("Case %d: No\n",++cas);
           else  printf("Case %d: Yes\n",++cas);
        }
        for(int i=0;i<mm;i++)edges[i].clear();
    }
}
