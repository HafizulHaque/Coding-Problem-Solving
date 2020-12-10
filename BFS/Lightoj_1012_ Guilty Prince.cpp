#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
char ara[40][40];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int vis[40][40];
int m,n;
int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    int count=1;
    while(!q.empty())
    {
        pii top=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(tx>=0 and tx<n and ty>=0 and ty<m and vis[tx][ty]==0 and ara[tx][ty]=='.')
            {
                vis[tx][ty]=1;
                count++;
                q.push(pii(tx,ty));
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;o++){
        int p,q,flag=0;
        cin>>m>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  cin>>ara[i][j];
                  if(ara[i][j]=='@'&&flag==0){
                    p=i;
                    q=j;
                    flag=1;
                  }
            }
        }
        memset(vis,0,sizeof(vis));
        int z=bfs(p,q);
        cout<<"Case "<<o<<": "<<z<<endl;
    }
return 0;
}
