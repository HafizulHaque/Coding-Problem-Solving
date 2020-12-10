#include<bits/stdc++.h>
using namespace std;

#define mx 20010

vector<int>edges[mx],Redges[mx],in[mx],out[mx],components[mx],finaledges[mx],num;
stack<int>st;
bool vis[mx];
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
        in[i].clear();
        out[i].clear();
    }
    num.clear();
    my.clear();
}

int main()
{
        int t;
        //freopen("out.txt","w",stdout);
        scanf("%d",&t);

        for(int cas=1;cas<=t;cas++){
            int n,e,a,b;
            scanf("%d %d",&n,&e);

            for(int i=0;i<e;i++){
                scanf("%d %d",&a,&b);
                edges[a].push_back(b);
                Redges[b].push_back(a);
            }

            strong_c_c(n);

            for(int d=0;d<num.size();d++){
                int i=num[d];
               // cout<<"main "<<i<<endl;
                int g=components[i].size();
                for(int j=0;j<g;j++){
                    int v=components[i][j];
                  // cout<<v<<endl;
                    finaledges[i].push_back(v);
                    my[v]=i;
                }
            }

            for(int i=1;i<=n;i++){
                   // cout<<"I "<<i<<endl;
                for(int j=0;j<finaledges[i].size();j++){
                    int u=finaledges[i][j];
                    //cout<<"u "<<u<<endl;
                    for(int k=0;k<edges[u].size();k++){
                        int v=edges[u][k];
                        //cout<<u<<' '<<v<<' '<<my[u]<<' '<<my[v]<<endl;
                        if(my[v]==my[u])continue;
                       out[i].push_back(my[v]);
                       in[my[v]].push_back(i);
                    }
                }
            }

            int count1=0,count2=0,value,cs=0;
            for(int i=1;i<=n;i++){
                //cout<<i<<' '<<my[i]<<' '<<in[i].size()<<' '<<out[i].size()<<endl;;
                if(my[i]!=i)continue;
                if(in[i].size()==0)count1++;
                if(out[i].size()==0)count2++;
                cs++;
            }
            if(cs==1)value=0;
            else value=max(count1,count2);

            printf("Case %d: %d\n",cas,value);
            clr();
    }
}



