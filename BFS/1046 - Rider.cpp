#include<bits/stdc++.h>
using namespace std;

#define mm 13
#define pii pair<int,int>
#define ff first
#define ss second
#define inf 1000000

int dx[]={-1,-2,-1,-2,1,2,1,2};
int dy[]={-2,-1,2,1,-2,-1,2,1};
char ara[mm][mm];
int shortest[mm][mm];
int visited[mm][mm];
int n,m;

int bfs(int x,int y,int z)
{
    //cout<<x<<' '<<y<<endl;
    visited[x][y]+=1;

    queue<pii>q;
    int vis[mm][mm],level[mm][mm];
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    q.push(pii(x,y));
    vis[x][y]=1;level[x][y]=0;

    while(!q.empty()){
        pii top=q.front();q.pop();
       // cout<<top.ff<<' '<<top.ss<<'m'<<endl;
        for(int k=0;k<8;k++){
            int tx=top.ff+dx[k];
            int ty=top.ss+dy[k];
            if(tx<1 or tx>n or ty<1 or ty>m)continue;
            if(vis[tx][ty]==1)continue;
            //cout<<tx<<' '<<ty<<endl;
            vis[tx][ty]=1;
            level[tx][ty]=level[top.ff][top.ss]+1;
            visited[tx][ty]+=1;
            if(level[tx][ty]%z==0){
                shortest[tx][ty]+=(level[tx][ty]/z);
            }
            else{
                 shortest[tx][ty]+=(level[tx][ty]/z)+1;
            }
           // cout<<shortest[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
    }
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&m);
        getchar();
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%c",&ara[i][j]);
                if(ara[i][j]=='.')continue;
                count++;
            }
            getchar();
        }
       // cout<<count<<endl;

        memset(shortest,0,sizeof(shortest));
        memset(visited,0,sizeof(visited));

        if(count<=1)printf("Case %d: 0\n",++cas);
        else{
           for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ara[i][j]=='.')continue;
                int x=ara[i][j]-'0';
                //cout<<x<<endl;
                bfs(i,j,x);
            }
           }
           int max=inf;

           for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                   // cout<<visited[i][j]<<' '<<shortest[i][j]<<endl;
                if(visited[i][j]==count){
                    if(shortest[i][j]<max){
                        max=shortest[i][j];
                    }
                }
            }
           }
           if(max==inf)max=-1;
           printf("Case %d: %d\n",++cas,max);
        }
    }
}
