#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
int ara[1010][1010];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int vis[1010][1010];
int d[1010][1010];
int m,n;

int bfs(int sx,int sy,int dx,int dy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d[i][j]=10000000;
        }
    }
    d[sx][sy]=0;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
		int cost=d[top.first][top.second];
           for(int k=0;k<4;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<m and ty>=0 and ty<n and cost+1<d[tx][ty]and ara[tx][ty]!=-1)
                {
                    d[tx][ty]=cost+1;
                    q.push(pii(tx,ty));
                }
            }
	}
    cout<<d[dx][dy]<<endl;
}
int main()
{
    while(cin>>m>>n){
        if(m==0||n==0)
            break;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ara[i][j]=0;
            }
        }
        int p,q,r,s;
        cin>>r;
        for(int i=1;i<=r;i++){
            cin>>p>>q;
            for(int j=0;j<q;j++){
                cin>>s;
                ara[p][s]=-1;
            }
        }
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        bfs(sx,sy,dx,dy);
    }
}

