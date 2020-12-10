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
    cout<<x<<' '<<y<<endl;
    if(ara[x][y]==destiny)
        return 1;

    vis[x][y]=1;
    int sum=0;

    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0 || xx>=r || yy<0 || yy>=c)continue;
        if(vis[xx][yy]) continue;
        if(ara[xx][yy]=='#') continue;

        sum=max(sum,DFS(xx,yy));
    }
    return sum;
}

int main()
{
    while(cin>>r>>c){
        destiny='A';
        clean(vis,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cin>>ara[i][j];
        }

        cout<<DFS(0,0)<<endl;

    }
}
