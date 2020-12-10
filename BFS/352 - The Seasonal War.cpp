#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
char ara[30][30];
int fx[]={1,-1,0,0,1,-1,-1,1};
int fy[]={0,0,1,-1,1,-1,1,-1};
int vis[30][30];
int m;
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
                if(tx>=0 and tx<m and ty>=0 and ty<m and ara[tx][ty]=='1' and vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    q.push(pii(tx,ty));
                }
            }
    }
}
int main()
{
    int o=1;
    while(cin>>m){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                cin>>ara[i][j];
        }
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(ara[i][j]=='1'&&vis[i][j]==0){
                    bfs(i,j);
                    count++;
                }
            }
        }
        cout<<"Image number "<<o<<" contains "<<count<<" war eagles."<<endl;
        o++;
    }
}

