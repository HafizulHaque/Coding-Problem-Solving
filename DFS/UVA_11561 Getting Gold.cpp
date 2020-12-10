#include<bits/stdc++.h>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
char maze[70][70];
int vis[70][70],value[70][70];
int w,h,coun;

int check(int x,int y)
{
    int flag=0;
    for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
        if(xx<0 or xx>h or yy<0 or yy>w)continue;
        if(maze[xx][yy]=='T'){
            flag=1;
            break;
        }
    }
    return flag;
}
int dfs(int x,int y,int c)
{
    vis[x][y]=1;
    int q=check(x,y);
    //cout<<"check "<<x<<' '<<y<<' '<<q<<' '<<c<<endl;
    if(q==1)return c;
    int mx=c;
    for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
        if(xx<0 or xx>h or yy<0 or yy>w)continue;
        if(vis[xx][yy]==1)continue;
        if(maze[xx][yy]=='#')continue;
         cout<<xx<<' '<<yy<<' '<<c<<endl;
        if(maze[xx][yy]=='.'){
            mx=max(c,dfs(xx,yy,c));
        }
        else{
            mx=max(c,dfs(xx,yy,c+1));
        }
    }
    cout<<"count "<<x<<' '<<y<<' '<<mx<<endl;
    return mx;
}
int main()
{
    while(cin>>w>>h){
        int x,y,a,b;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='P'){
                    x=i;y=j;
                }
            }
        }
        cout<<x<<' '<<y<<endl;
        cout<<dfs(x,y,0)<<endl;
         memset(vis,0,sizeof(vis));
    }
}
