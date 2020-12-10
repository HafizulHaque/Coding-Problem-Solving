#include<bits/stdc++.h>
using namespace std;

#define clean(a,b) memset(a,b,sizeof(a));
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

char ara[110][110];
int vis[100][100];
int r,c,destiny;

int DFS(int x,int y)
{
    //cout<<x<<' '<<y<<' '<<ara[x][y]<<endl;

    ara[x][y]='*';

    for(int i=0;i<8;i++){
       int xx=x+dx[i];
       int yy=y+dy[i];
       if(xx<0 or xx>=r or yy<0 or yy>=c) continue;
       if(ara[xx][yy]=='*') continue;
       //cout<<xx<<' '<<yy<<' '<<ara[xx][yy]<<endl;
       DFS(xx,yy);
    }
    return 0;
}
int main()
{
    while(cin>>r>>c)
    {
        if(r==0 && c==0)
            break;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>ara[i][j];
            }
        }
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ara[i][j]=='@'){
                    count++;
                    DFS(i,j);
                }
            }
        }
        cout<<count<<endl;
    }
}
