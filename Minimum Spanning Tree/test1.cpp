#include<bits/stdc++.h>
using namespace std;

#define mm 10010
int pr[mm];
int vis[mm];
int c=0,a;
struct vertex
{
    int u,v,w;
    bool operator <(const vertex &p)const
    {
        return w<p.w;
    }
};
vector<vertex>edges;

int find_r(int r)
{
    if(pr[r]==r)return r;
    else{
        pr[r]=find_r(pr[r]);
        return pr[r];
    }
}
int mst(int n)
{
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++)pr[i]=i;
    int count=0,s=0;

    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);
        if(u!=v){
            pr[u]=v;
            count++;
          //  cout<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
            if(edges[i].w>=a){
                    c++;
                    s+=a;
            }
            else s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    //cout<<count<<endl;
    //cout<<"s "<<s<<endl;
    return s;
}

int main()
{
    int t,u,v,w,cas=0;
    scanf("%d",&t);

    while(t--){
        int n,m;
        scanf("%d%d%d",&n,&m,&a);
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            vertex get;
            vis[u]=1;
            vis[v]=1;
            get.u=u;get.v=v;get.w=w;

            edges.push_back(get);
        }

        int count=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1)count++;
        }

        int x=n-count;

        int s=mst(n)+x*a;

       // cout<<s<<endl;

        for(int i=1;i<=n;i++){
            if(vis[i]==0)continue;
            find_r(i);
        }
        count=0;

        for(int i=1;i<=n;i++){
               // cout<<"v "<<vis[i]<<endl;
            if(vis[i]==0)continue;
            if(vis[i]==2)continue;
                count++;
          //  cout<<"p "<<pr[i]<<' '<<i<<endl;

            for(int j=i;j<=n;j++){
                if(vis[j]==0)continue;
                //cout<<pr[j]<<' '<<pr[i]<<endl;
                if(pr[i]==pr[j]){
                    vis[j]=2;
                }
            }
        }
       // cout<<count<<endl;
        s+=count*a;
        //cout<<s<<' '<<count<<' '<<x<<' '<<c<<endl;
        printf("Case %d: %d %d\n",++cas,s,count+c+x);
        edges.clear();
        c=0;
    }
}

