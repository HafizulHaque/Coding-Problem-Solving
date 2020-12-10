#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define inf 1000000010
#define pii pair<lli,lli>
vector<pii>edges[10010],edgesr[10010];
lli dr[10010],dis[10010],mxx[10010];

struct st
{
    lli u,w;
    st(lli a,lli b){u=a;w=b;}
    bool operator < (const st &p)const{return w>p.w;}
};

lli result(lli n,lli s,lli p)
{
    for(lli i=0;i<=n;i++)dis[i]=inf,mxx[i]=-1;
    dis[s]=0;

    priority_queue<st>q;
    q.push(st(s,0));

    while(!q.empty())
    {
        st x=q.top();q.pop();
        lli u=x.u,c=x.w,m=mxx[u];
        for(lli i=0;i<edges[u].size();i++){
            lli uu=edges[u][i].first;
            lli cc=edges[u][i].second;
            lli l=max(m,cc);
            if(c+cc+dr[uu]>p)continue;
            if(l>mxx[uu]){
                mxx[uu]=l;
                q.push(st(uu,dis[uu]));
            }
            if(c+cc<dis[uu]){
                dis[uu]=c+cc;
                q.push(st(uu,c+cc));
            }
        }
    }

}
lli dijkastra(lli n,lli d)
{
    for(lli i=0;i<=n;i++)dr[i]=inf;
    dr[d]=0;

    priority_queue<st>q;
    q.push(st(d,0));

    while(!q.empty())
    {
        st x=q.top();q.pop();
        lli u=x.u,c=x.w;
        for(lli i=0;i<edgesr[u].size();i++){
            lli uu=edgesr[u][i].first;
            lli cc=edgesr[u][i].second;
            if(c+cc<dr[uu]){
                dr[uu]=c+cc;
                q.push(st(uu,c+cc));
            }
        }
    }
}
int main()
{
    lli n,m,s,d,p,t,cs=0;
    cin>>t;
    while(t--){
        scanf("%lld %lld %lld %lld %lld",&n,&m,&s,&d,&p);
        lli x,y,z;

        for(lli i=0;i<m;i++){
            scanf("%lld %lld %lld",&x,&y,&z);
            edges[x].push_back(pii(y,z));
            edgesr[y].push_back(pii(x,z));
        }
        dijkastra(n,d);
        result(n,s,p);
        printf("Case %lld: %lld\n",++cs,mxx[d]);
        for(lli i=0;i<10010;i++)edges[i].clear(),edgesr[i].clear();
    }
}
