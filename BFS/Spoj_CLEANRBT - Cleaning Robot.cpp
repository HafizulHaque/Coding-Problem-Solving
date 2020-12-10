#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
string ara[50];
int vis[50][50];
int level[50][50];
int vis1[50][50];
int r,c,count=0;

int bfs(int srcx,int srcy,int cu)
{
    queue<pii>q;
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    q.push(pii(srcx,srcy));
    level[srcx][srcy]=0;
    vis[srcx][srcy]=1;

    int z=cu;
    while(!q.empty()){
        pii top=q.front();q.pop();
        int sx,sy;
        sx=top.first;sy=top.second;
       // cout<<sx<<' '<<sy<<endl;
        for(int k=0;k<4;k++){
            int tx=sx+dx[k];
            int ty=sy+dy[k];
           // cout<<tx<<' '<<ty<<endl;

            if(tx<0 or tx>=r or ty<0 or ty>=c)continue;
            if(vis[tx][ty]==1 or vis1[tx][ty]==1)continue;

            if(ara[tx][ty]=='*'){
                vis[tx][ty]=1;
                ara[tx][ty]='.';
                level[tx][ty]=level[sx][sy]+1;
                z+=level[tx][ty];
                //cout<<tx<<' '<<ty<<' '<<z<<endl;
                z=max(z,bfs(tx,ty,z));
            }
            else{
                vis[tx][ty]=1;
                level[tx][ty]=level[sx][sy]+1;
                q.push(pii(tx,ty));
            }
        }
    }
    //cout<<srcx<<' '<<srcy<<' '<<z<<" l"<<endl;
    return z;
}
int main()
{
    while(cin>>c>>r){
        if(c==0 or r==0)break;
        for(int i=0;i<r;i++)cin>>ara[i];
         int x,y;
        memset(vis1,0,sizeof(vis1));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ara[i][j]=='x')vis1[i][j]=1;
                if(ara[i][j]=='o'){x=i;y=j;}
            }
        }
        //cout<<x<<' '<<y<<endl;

        int max=bfs(x,y,0);
        //cout<<max<<endl;
        int flag=0;
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
             ///cout<<ara[i][j];
                if(ara[i][j]=='*'){
                    flag=1;
                    break;
                }
            }
            //cout<<endl;
        }
        if(flag==1)cout<<-1<<endl;
        else cout<<max<<endl;
    }
}
