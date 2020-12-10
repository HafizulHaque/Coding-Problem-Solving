#include<bits/stdc++.h>
using namespace std;
#define clean(a,b) memset(a,0,sizeof(a))
#define pii pair<int,int>

int fx[]={0,1,0,-1};
int fy[]={-1,0,1,0};

char ara[50][50];
int vis[50][50];
int dis[50][50];
int r,c,count=0;

int bfs(int x,int y)
{
    //cout<<x<<' '<<y<<endl;
    clean(vis,0);clean(dis,0);
    vis[x][y]=1;
    dis[x][y]=0;
    int count=0,flag=0;
    queue<pii>q;
    q.push(pii(x,y));

    while(!q.empty()){
        pii top=q.front();q.pop();

        for(int k=0;k<4;k++){
            int xx=top.first+fx[k];
            int yy=top.second+fy[k];
           // cout<<xx<<' '<<yy<<endl;
            if(xx<0 or xx>=r or yy<0 or yy>=c) continue;
            if(ara[xx][yy]=='#' or ara[xx][yy]=='m' or vis[xx][yy]==1) continue;
           // count++;
            vis[xx][yy]=1;
            dis[xx][yy]=dis[top.first][top.second]+1;
            if(ara[xx][yy]=='h'){
                    count=dis[xx][yy];
                flag=1;
                break;
            }
            q.push(pii(xx,yy));
        }
        if(flag==1)
            break;
    }
    //cout<<x<<' '<<y<<' '<<count<<endl;
    return count;
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        cin>>r>>c;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cin>>ara[i][j];
        }
        clean(vis,0);

        int count=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ara[i][j]=='a'||ara[i][j]=='b'||ara[i][j]=='c' && vis[i][j]==0){
                    //cout<<i<<' '<<j<<' '<<ara[i][j]<<endl;
                    count=max(count,bfs(i,j));
                    //cout<<count<<endl;
                    clean(vis,0);
                }
            }
        }
         cout<<"Case "<<++cas<<": "<<count<<endl;
    }
}
