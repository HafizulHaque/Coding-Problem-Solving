#include<bits/stdc++.h>
using namespace std;

#define mx 1010

vector<int>edges[mx],Redges[mx],components[mx],finaledges[mx],num;
stack<int>st;
bool vis[mx],finalvis[mx],unused[mx];
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
    for(int i=0;i<mx;i++){
        if(vis[i]==1 or unused[i]==0)continue;
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
    finalvis[src]=1;
    int count=1;

    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(finaledges[u].size()>1)return 0;
        for(int i=0;i<finaledges[u].size();i++){
                int v=finaledges[u][i];
            if(finalvis[v]==1)continue;
            finalvis[v]=1;
            count++;
            q.push(v);
        }
    }
    return count;
}

int main()
{
        int t;
        scanf("%d ",&t);

        for(int cas=1;cas<=t;cas++){
            int n,e,a,b;
            scanf("%d",&n);

            memset(unused,0,sizeof(unused));
            memset(finalvis,0,sizeof(finalvis));

            for(int k=0;k<n;k++){
                scanf("%d",&e);
                for(int i=0;i<e;i++){
                    scanf("%d %d",&a,&b);
                    unused[a]=unused[b]=1;
                    edges[a].push_back(b);
                    Redges[b].push_back(a);
                }
            }

            strong_c_c(n);
            int flag=0;
            vector<int>vtt;
            for(int d=0;d<num.size();d++){
                int i=num[d];
               // cout<<"I "<<i<<endl;
                int a=components[i].size();
                int mn=10000;
                for(int j=0;j<a;j++){
                    int v=components[i][j];
                    mn=min(mn,v);
                    vtt.push_back(v);
                }
                //cout<<mn<<endl;
                for(int l=0;l<vtt.size();l++){
                    int v=vtt[l];
                    my[v]=mn;
                    if(mn==0)flag=1;
                    //cout<<mn<<' '<<v<<endl;
                    finaledges[mn].push_back(v);
                }
                vtt.clear();
            }
            vtt.clear();
            for(int i=0;i<mx;i++){
                int a=finaledges[i].size();
                for(int j=0;j<a;j++){
                    int u=finaledges[i][j];
                    for(int k=0;k<edges[u].size();k++){
                        int v=edges[u][k];
                        //cout<<u<<' '<<my[u]<<' '<<v<<' '<<my[v]<<endl;
                        if(my[v]==my[u])continue;
                        //cout<<my[v]<<endl;
                        vtt.push_back(my[v]);
                    }
                }
                finaledges[i].clear();
                for(int l=0;l<vtt.size();l++){
                    int v=vtt[l];
                    finaledges[i].push_back(v);
                }
                vtt.clear();
            }

            /**for(int i=0;i<mx;i++){
                if(finaledges[i].size()==0)continue;
                cout<<"i "<<i<<endl;
                for(int j=0;j<finaledges[i].size();j++){
                    cout<<finaledges[i][j]<<' ';
                }
                cout<<endl;
            }**/
            int count=num.size();
           // cout<<count<<endl;
            if(flag==0)count++;
            //cout<<count<<endl;
            int x=bfs(0);
            //cout<<x<<endl;
            if(x!=count)x=0;
            else x=1;
           // cout<<x<<endl;
            if(x==1)printf("Case %d: YES\n",cas);
            else printf("Case %d: NO\n",cas);

            clr();
    }
}






