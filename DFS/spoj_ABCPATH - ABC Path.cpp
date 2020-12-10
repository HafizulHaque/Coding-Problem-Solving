#include<bits/stdc++.h>
using namespace std;

#define clean(a,b) memset(a,b,sizeof(a));
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

char ara[110][110];
int vis[100][100];
int r,c,destiny;

int DFS(int x,int y,int v)
{
    //cout<<x<<' '<<y<<' '<<ara[x][y]<<endl;
    vis[x][y]=1;
    int z=v;
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0 || xx>=r || yy<0 || yy>=c)continue;
        if(vis[xx][yy]==1) continue;
       // cout<<xx<<' '<<yy<<' '<<ara[xx][yy]<<' '<<char(ara[x][y]+1)<<endl;
        if(ara[xx][yy]==char(ara[x][y]+1))
          z=max(z,DFS(xx,yy,v+1));
        }
    //cout<<x<<' '<<y<<' '<<ara[x][y]<<' '<<z<<endl;
    return z;
}
int main()
{
    int cas=0;
    while(cin>>r>>c){
        if(r==0 or c==0)
            break;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cin>>ara[i][j];
        }

        int count=0;
        clean(vis,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ara[i][j]=='A'){
                    clean(vis,0);
                    count=max(count,DFS(i,j,1));
                    //cout<<count<<endl;
                }
            }
        }
        cout<<"Case "<<++cas<<": "<<count<<endl;
    }
}
