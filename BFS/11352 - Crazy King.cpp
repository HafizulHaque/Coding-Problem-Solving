#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
char ara[110][110];
int fx[]={-1,-2,-1,-2,1,2,1,2};
int fy[]={-2,-1,2,1,-2,-1,2,1};
int f1x[]={1,-1,0,0,1,-1,-1,1};
int f2y[]={0,0,1,-1,1,-1,1,-1};
int vis[110][110];
int m,n,p,q,r,s;

int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;

    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<8;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<m and ty>=0 and ty<n and ara[tx][ty]=='.' and vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    //q.push(pii(tx,ty));
                }
            }
    }
}

int bfs1(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    int d[m+1][n+1];
    vis[sx][sy]=1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            d[i][j]=1000000;
    }

    d[sx][sy]=0;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
            int cost=d[top.first][top.second];
           for(int k=0;k<8;k++){
                int tx=top.first+f1x[k];
                int ty=top.second+f2y[k];
                if(tx>=0 and tx<m and ty>=0 and ty<n and cost+1<d[tx][ty] and vis[tx][ty]==0)
                {
                    d[tx][ty]=cost+1;
                    q.push(pii(tx,ty));
                }
            }
    }

    if(d[r][s]>=1000000)
        cout<<"King Peter, you can't go now!"<<endl;
    else
        cout<<"Minimal possible length of a trip is "<<d[r][s]<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;o++){
        int flag=0,flag1=0;
        cin>>m>>n;
        memset(vis,0,sizeof(vis));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>ara[i][j];
                if(ara[i][j]=='A'&&flag==0){
                    p=i,q=j;
                    flag=1;
                }
                if(ara[i][j]=='B'&&flag1==0){
                    r=i,s=j;
                    flag1=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ara[i][j]=='Z'&&vis[i][j]==0){
                    bfs(i,j);
                }
            }
        }

        bfs1(p,q);


    }
}
