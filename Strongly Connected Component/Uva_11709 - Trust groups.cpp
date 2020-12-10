#include<bits/stdc++.h>
using namespace std;

#define mx 1010

vector<int>edges[mx],Redges[mx],components[mx],finaledges[mx],num;
stack<int>st;
bool vis[mx];
map<string ,int>my;

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

int main()
{
        int n,e;

        while(cin>>n>>e){
            if(n==0 and e==0)break;
            string s,s1;
            getline(cin,s);
            for(int i=1;i<=n;i++){
                getline(cin,s);
                my[s]=i;
               // cout<<s<<' '<<my[s]<<endl;
            }

            int a,b;
            for(int i=0;i<e;i++){
                getline(cin,s);
                getline(cin,s1);
                a=my[s];b=my[s1];

                //cout<<a<<' '<<b<<endl;
                edges[a].push_back(b);
                Redges[b].push_back(a);
            }

            strong_c_c(n);
            cout<<num.size()<<endl;
            clr();
        }
}





