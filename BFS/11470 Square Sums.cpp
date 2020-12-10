#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
int  ara[20][20];
int fx[]={1,0};
int fy[]={0,1};
int vis[20][20];
int m,n;
int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    int sum=ara[sx][sy];
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<2;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=sx and tx<m-sx and ty>=sy and ty<m-sy and (((tx==sx||tx==m-sx-1)and(ty>=sy||ty<m-sy))or((ty==sy||ty==m-sy-1)and(tx>=sx||tx<m-sx))) and vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    sum+=ara[tx][ty];
                    q.push(pii(tx,ty));
                }
            }
        }
        return sum;
}
int main()
{
    int o=1;
    while(cin>>m&&m!=0){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin>>ara[i][j];
            }
        }
        if(m%2!=0)n=(m/2)+1;
        else n=m/2;
        int my[n+1];
        int k=0;
        for(int i=0,j=0;i<n;i++,j++){
                memset(vis,0,sizeof(vis));
            my[k]=bfs(i,j);
            k++;
        }
        cout<<"Case "<<o<<':';
        for(int i=0;i<k;i++)
            cout<<' '<<my[i];
        cout<<endl;
        o++;
    }
}
