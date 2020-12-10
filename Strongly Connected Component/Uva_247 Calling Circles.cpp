#include<bits/stdc++.h>
using namespace std;

#define mx 30

vector<int>edges[mx],Redges[mx],components[mx],num;
stack<int>st;
bool vis[mx];
map<string,int>my1;
map<int,string>my2;

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
    }
    num.clear();
    my1.clear();my2.clear();
}

int main()
{
        int t=0;
        int n,e,a,b;
        while(cin>>n>>e){
            string s,s1;
            if(n==0)break;
            if(t!=0)cout<<endl;
            int c=1;
            my1.clear();my2.clear();

            for(int i=0;i<e;i++){
                cin>>s>>s1;

                if(my1[s]==0)my1[s]=c++;
                if(my1[s1]==0)my1[s1]=c++;
                a=my1[s];b=my1[s1];
                my2[a]=s;my2[b]=s1;

                edges[a].push_back(b);
                Redges[b].push_back(a);
            }

            strong_c_c(n);

            printf("Calling circles for data set %d:\n",++t);
            for(int d=0;d<num.size();d++){
                int i=num[d];
                //cout<<i<<endl;
                int g=components[i].size();
                for(int j=0;j<g;j++){
                    int v=components[i][j];
                   // cout<<v<<' ';
                    if(j==g-1)cout<<my2[v]<<endl;
                    else cout<<my2[v]<<", ";
                }
            }
            clr();
        }
}





