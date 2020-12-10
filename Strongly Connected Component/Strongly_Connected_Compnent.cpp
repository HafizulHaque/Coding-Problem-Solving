#include<bits/stdc++.h>
using namespace std;

#define mx 10010

vector<int>edges[mx],Redges[mx],components[mx],num;
stack<int>st;
bool vis[mx];

/// sort the graph according to finishing time
int dfs1(int x)
{
    vis[x]=1;
    int a=edges[x].size();
    for(int i=0;i<a;i++){
        int v=edges[x][i];
        if(vis[v]==1)continue;
        dfs1(v);
    }
   // cout<<x<<endl;
    st.push(x);
    return 0;
}

///Find the components or cycles
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

///finding strongly connected component
int strong_c_c(int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        dfs1(i);
    }

    memset(vis,0,sizeof(vis));
    int c=1;
    while(!st.empty()){
        int u=st.top();st.pop();
        if(vis[u]==1)continue;
        dfs2(u,u);
        num.push_back(u);
    }
}

int main()
{
    int n,e,a,b;
    scanf("%d %d",&n,&e);

    for(int i=0;i<e;i++){
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        Redges[b].push_back(a);
    }

    strong_c_c(n);

    for(int i=0;i<num.size();i++){
        b=num[i];
        cout<<b<<' '<<components[b].size()<<endl;
        for(int j=0;j<components[b].size();j++){
            int v=components[b][j];
            cout<<v<<' ';
        }
        cout<<endl;
    }
}
/**
7 8

1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
**/

