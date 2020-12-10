#include<bits/stdc++.h>
using namespace std;

#define mx 50010
int level[mx],vis[mx],par[mx],sparse[mx][15],n;
vector<int>edges[mx];

void dfs(int node)
{
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i];
        if(vis[v]==1)continue;
        vis[v]=1;
        level[v]=level[node]+1;
        par[v]=node;
        dfs(v);
    }
}

int init()
{
    memset(sparse,-1,sizeof sparse);
    for(int i=1;i<=n;i++)sparse[i][0]=par[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(sparse[i][j-1]!=-1)sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}

int query(int p,int q)
{
    if(level[p]<level[q])swap(p,q);
    int m=log2(level[p]);

    for(int i=m;i>=0;i--){
        if(level[p]-(1<<i)>=level[q])p=sparse[p][i];
    }
    if(p==q)return p;
    m=log2(level[p]);

    for(int i=m;i>=0;i--){
        if(sparse[p][i]!=-1 and sparse[p][i]!=sparse[q][i]){
            p=sparse[p][i];
            q=sparse[q][i];
        }
    }
    return par[p];
}
int child(int u,int k)
{
    int m=log2(k);
    for(int i=m;i>=0;i--){
        if(k-(1<<i)>=0){
            u=sparse[u][i];
            k=k-(1<<i);
        }
    }
    return u;
}
void clr()
{
    memset(level,0,sizeof level);
    memset(par,-1,sizeof par);
    memset(vis,0,sizeof vis);
    for(int i=0;i<mx;i++)edges[i].clear();
}
int main()
{
    while(cin>>n){
        if(n==0)break;
        int u,v,l,r,s,a,b;
        clr();
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vis[1]=1; dfs(1); init();
        scanf("%d",&l);

        while(l--){
            scanf("%d %d",&u,&v);
            int x=query(u,v);
            int d=level[u]+level[v]-2*level[x];

            if(d%2==0){
                if(level[u]-level[x]>=(d/2))
                    r=child(u,(d/2));
                else r=child(v,(d/2));
                printf("The fleas meet at %d.\n",r);
            }
            else{
                a=(d/2),b=(d+1)/2;
                if(level[u]-level[x]<a){
                    r=child(v,a);
                    s=child(v,b);
                }
                else if(level[u]-level[x]==a){
                    r=child(u,a);
                    s=child(v,a);
                }
                else{
                    r=child(u,a);
                    s=child(u,b);
                }
                printf("The fleas jump forever between %d and %d.\n",min(r,s),max(r,s));
            }
        }
    }
}
