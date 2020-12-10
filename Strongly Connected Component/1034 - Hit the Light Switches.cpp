#include<bits/stdc++.h>
using namespace std;

#define mx 10010

vector<int>edges[mx],Redges[mx],components[mx],finaledges[mx],num;
stack<int>st;
bool vis[mx],finalvis[mx];
map<int,int>my;

int dfs1(int x)
{
    vis[x]=1;
    int a=edges[x].size();
    for(int i=0;i<a;i++){
        int v=edges[x][i];
        if(vis[v]==1)continue;
        dfs1(v);
    }
    st.push(x);
    return 0;
}

int dfs2(int u,int c)
{
    vis[u]=1;
    components[c].push_back(u);
    int s=Redges[u].size();

    for(int i=0;i<s;i++){
        int v=Redges[u][i];
        if(vis[v]==1)continue;
        dfs2(v,c);
    }
    return 0;
}

int strong_c_c(int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        dfs1(i);
    }

    memset(vis,0,sizeof(vis));
    while(!st.empty()){
        int u=st.top();st.pop();
        if(vis[u]==1)continue;
        dfs2(u,u);
        num.push_back(u);
    }
}

void clr()
{
    for(int i=0;i<mx;i++){
        edges[i].clear();
        Redges[i].clear();
        components[i].clear();
        finaledges[i].clear();
    }
    num.clear();
    my.clear();
}

int bfs(int src)
{
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<finaledges[u].size();i++){
            int v=finaledges[u][i];
            if(finalvis[v]==1 or v==src)continue;
            finalvis[v]=1;
            q.push(v);
        }
    }
}

int main()
{
        int t;
        scanf("%d ",&t);

        for(int cas=1;cas<=t;cas++){
        int n,e,a,b;
        scanf("%d %d",&n,&e);

        for(int i=0;i<e;i++){
            scanf("%d %d",&a,&b);
            edges[a].push_back(b);
            Redges[b].push_back(a);
        }

        strong_c_c(n);
        memset(finalvis,0,sizeof(finalvis));

        for(int d=0;d<num.size();d++){
            int i=num[d];
            int g=components[i].size();
            for(int j=0;j<g;j++){
                int v=components[i][j];
                finaledges[i].push_back(v);
                my[v]=i;
            }
        }

        vector<int>vtt;
        for(int i=1;i<=n;i++){
            for(int j=0;j<finaledges[i].size();j++){
                int u=finaledges[i][j];
                for(int k=0;k<edges[u].size();k++){
                    int v=edges[u][k];
                    if(my[v]==my[u])continue;
                    vtt.push_back(my[v]);
                }
            }
            for(int l=0;l<vtt.size();l++){
                finaledges[i].push_back(vtt[l]);
            }
            vtt.clear();
        }

        for(int i=1;i<=n;i++){
            if(finalvis[i]==1)continue;
            bfs(i);
        }

        int count=0;
        for(int i=1;i<=n;i++){
            if(finalvis[i]==0)count++;
        }
        printf("Case %d: %d\n",cas,count);
        clr();
    }
}



