#include<bits/stdc++.h>
using namespace std;

#define mm 1000010
int pr[mm];

struct vertex
{
    int u,v,w;
    bool operator <(const vertex& p)const
    {
        return w<p.w;
    }
};

vector <vertex>edges;

int find_r(int r)
{
    if(pr[r]==r)return r;
    else{
        pr[r]=find_r(pr[r]);
        return pr[r];
    }
}

long long mst(int n)
{
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++)pr[i]=i;

    long long count=0,s=0;
    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);
        //cout<<u<<' '<<v<<endl;
        if(u!=v){
            count++;
            pr[u]=v;
            //cout<<edges[i].w<<endl;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    //cout<<s<<endl;
    return s;
}

int main()
{
   long n,m,k,u,v,w,t=0;

   while(cin>>n){
        if(t>0)cout<<endl;
        t++;

        long long s=0;
        memset(pr,0,sizeof(pr));
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            s+=w;
        }

        scanf("%d",&k);

        for(int i=1;i<=k;i++){
             scanf("%d%d%d",&u,&v,&w);
             vertex get;
             get.u=u;get.v=v;get.w=w;
             edges.push_back(get);
        }

        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }

        cout<<s<<endl;
        cout<<mst(m+k)<<endl;
        edges.clear();
   }
}
