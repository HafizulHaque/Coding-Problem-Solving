#include<bits/stdc++.h>
using namespace std;

#define pii pair <int,int>
#define clean(a,b) memset(a,0,sizeof(a))
#define uu first
#define vv second
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

#define inf 1000000

string ara[205];
int r,c;
pii star1,star2;

int findstar2(int sx,int sy)
{

    int vis[205][205];
    int d[205][205];
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));

    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    d[sx][sy]=0;
    int l=0;

    while(!q.empty()){
        pii top=q.front();q.pop();

        for(int k=0;k<4;k++){
            int tx=top.first+dx[k];
            int ty=top.second+dy[k];

            if(tx<1 or tx>r or ty<1 or ty>c) continue;
            if(ara[tx][ty]=='#') continue;
            if(!vis[tx][ty]){
                if(ara[tx][ty]=='*'){
                star2=pii(tx,ty);
                vis[tx][ty]=1;
                l=d[top.uu][top.vv]+1;
                    while(!q.empty()){
                    q.pop();
                }
               break;
                }
                else if(ara[tx][ty]=='.'){
                     vis[tx][ty]=1;
                    d[tx][ty]=d[top.uu][top.vv]+1;
                    q.push(pii(tx,ty));
                }
            }
        }
    }
    cout<<star2.uu<<' '<<star2.vv<<endl;
    cout<<l<<endl;
    return l;

}

int findstar1(int sx,int sy)
{
    int vis[205][205];
    int d[205][205];
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));

    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    d[sx][sy]=0;
    int l=0;
    while(!q.empty()){
        pii top=q.front();q.pop();

        for(int k=0;k<4;k++){
            int tx=top.first+dx[k];
            int ty=top.second+dy[k];

            if(tx<1 or tx>r or ty<1 or ty>c) continue;
            if(ara[tx][ty]=='#') continue;
            if(!vis[tx][ty]){
                    if(ara[tx][ty]=='*'){
                    star1=pii(tx,ty);
                    vis[tx][ty]=1;
                    l=d[top.uu][top.vv]+1;
                   while(!q.empty()){
                        q.pop();
                   }
                   break;
                }
                else if(ara[tx][ty]=='.'){
                    vis[tx][ty]=1;
                    d[tx][ty]=d[top.uu][top.vv]+1;
                    q.push(pii(tx,ty));
                }
            }
        }
    }

    cout<<star1.uu<<' '<<star1.vv<<endl;
    cout<<l<<endl;
    return l;
}

int bfs(int sx,int sy)
{
     int vis[205][205];
    int d[205][205];
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));

    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    d[sx][sy]=0;
    int l=inf;

    while(!q.empty()){
        pii top=q.front();q.pop();

        for(int k=0;k<4;k++){
            int tx=top.first+dx[k];
            int ty=top.second+dy[k];

            if(tx<1 or tx>r or ty<1 or ty>c) continue;
            if(ara[tx][ty]=='#' or ara[tx][ty]=='*') continue;
            if(!(vis[tx][ty])){
                if(ara[tx][ty]=='D'){
                    vis[tx][ty]=1;
                    l=d[top.uu][top.vv]+1;
                   while(!q.empty()){
                    q.pop();
                   }
                   break;
                }
                else if(ara[tx][ty]=='.'){
                    vis[tx][ty]=1;
                    d[tx][ty]=d[top.uu][top.vv]+1;
                    q.push(pii(tx,ty));
                }
            }
        }
    }
    cout<<l<<endl;
    return l;
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&r,&c);
        pii p,d;

        for(int i=1;i<=r;i++)cin>>ara[i];
        int count=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(ara[i][j]=='P'){
                  p=pii(i,j);
                }
                if(ara[i][j]=='D'){
                    d=pii(i,j);
                }
                if(ara[i][j]=='*')
                    count++;
            }
        }

        int sp;
        star1.first=0; star2.first=0;
        star1.second=0;star2.second=0;
        cout<<p.uu<<' '<<p.vv<<endl;
        cout<<d.uu<<' '<<d.vv<<endl;

        int c1=findstar1(p.uu,p.vv);
        int c2=findstar2(d.uu,d.vv);

        cout<<star1.uu<<' '<<star1.vv<<' '<<c1<<endl;
        cout<<star2.uu<<' '<<star2.vv<<' '<<c2<<endl;

        if(c1==0 or c2==0)
            sp=inf;
        else if(star1==star2){
            if(count>=2)sp=c1+c2+2;
            else sp=inf;
        }
        else if(star1!=star2){
            sp=c1+c2+1;
        }

        int x=bfs(p.uu,p.vv);
        cout<<x<<endl;

        if(x==inf and sp==inf){
            printf("Case %d: impossible\n",++cas);
        }
        else{
             printf("Case %d: %d\n",++cas,min(x,sp));
        }
    }
}
