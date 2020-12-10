
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
char ara[110][110];
int fx[]={1,-1,0,0,1,-1,-1,1};
int fy[]={0,0,1,-1,1,-1,1,-1};
int vis[110][110];
int m,n;
int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    int flag=1;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<8;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<m and ty>=0 and ty<n and ara[tx][ty]=='*' and vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    flag=2;
                    q.push(pii(tx,ty));
                }
            }
        }
        return flag;
}
int main()
{
    while(cin>>m>>n){
        if(m==0||n==0)
            break;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                cin>>ara[i][j];
        }
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ara[i][j]=='*'&&vis[i][j]==0){
                   int z=bfs(i,j);
                   if(z==1)
                    count+=z;
                }
            }
        }
        cout<<count<<endl;
    }
}
