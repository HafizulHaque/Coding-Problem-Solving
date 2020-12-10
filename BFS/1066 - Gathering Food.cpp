#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
string ara[15];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

int level[15][15];
int vis[15][15];
int n,g,c;
char destiny;

int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));

    level[sx][sy]=0;
    vis[sx][sy]=1;
    int count=0,x,y;

    while(!q.empty()){
        pii top=q.front();q.pop();
        x=top.first,y=top.second;
        for(int k=0;k<4;k++){
            int tx=x+dx[k];
            int ty=y+dy[k];

            if(tx<0 or tx>=n or ty<0 or ty>=n)continue;
            if(ara[tx][ty]=='#')continue;
            if(vis[tx][ty]==1)continue;

            if(ara[tx][ty]==destiny){
                level[tx][ty]=level[x][y]+1;
                count+=level[tx][ty];
                c++;
                while(!q.empty()){
                    q.pop();
                }

                if(c==g){
                    break;
                }

                destiny=char(ara[tx][ty]+1);
                memset(vis,0,sizeof(vis));
                memset(level,0,sizeof(level));
                vis[tx][ty]=1;
                level[tx][ty]=0;
                q.push(pii(tx,ty));
                break;
            }

            else if(ara[tx][ty]=='.' or ara[tx][ty]<destiny){
                 vis[tx][ty]=1;
                 level[tx][ty]=level[x][y]+1;
                 q.push(pii(tx,ty));
            }
        }
    }

    if(c!=g)return 0;
    else return count;
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        int x,y;
        c=1;
        g=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>ara[i];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ara[i][j]=='.' or ara[i][j]=='#')continue;
                g++;
                if(ara[i][j]=='A'){
                    x=i,y=j;
                }
            }
        }

        int count=0;
        destiny=char(ara[x][y]+1);

        if(c==g){
            printf("Case %d: %d\n",++cas,count);
        }
        else{
            count+=bfs(x,y);
            if(count==0)printf("Case %d: Impossible\n",++cas);
            else printf("Case %d: %d\n",++cas,count);
        }
    }
}

