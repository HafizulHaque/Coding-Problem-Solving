#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
char ara[60][60];
char ara1[60][60];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int vis[60][60];
int vis1[60][60];
int m,n;

int bfs1(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis1[sx][sy]=1;
    vis[sx][sy]=1;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<4;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<m and ty>=0 and ty<n and ara1[tx][ty]=='X' and vis1[tx][ty]==0)
                {
                    vis1[tx][ty]=1;
                    vis[tx][ty]=1;
                    q.push(pii(tx,ty));
                }
            }
        }
}

int my()
{
    int count=0;
    memset(vis1,0,sizeof(vis1));
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(ara1[i][j]=='X'&&vis1[i][j]==0){
                bfs1(i,j);
                count++;
            }
            }
        }

    return count;
}

int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    memset(ara1,0,sizeof(ara1));
    ara1[sx][sy]=ara[sx][sy];
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<4;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<m and ty>=0 and ty<n and (ara[tx][ty]=='X'||ara[tx][ty]=='*') and vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    ara1[tx][ty]=ara[tx][ty];
                    q.push(pii(tx,ty));
                }
            }
        }
        int y=my();
        return y;
}

int main()
{
    int o=1;
    while(cin>>n>>m){
        if(m==0||n==0)
            break;
        memset(vis,0,sizeof(vis));
        vector<int>v;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                cin>>ara[i][j];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((ara[i][j]=='X'||ara[i][j]=='*')&&vis[i][j]==0){
                   int z=bfs(i,j);
                    v.push_back(z);
                }
            }
        }

        sort(v.begin(),v.end());
        cout<<"Throw "<<o<<endl;
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1)
                cout<<v[i]<<endl;
            else
                cout<<v[i]<<' ';
        }
        cout<<endl;
        o++;
    }
}
