#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int srx,sry,dex,dey;

int bfs(int x,int y)
{
    queue<pii>q;
    int vis[10][10];
    int level[10][10];
    pii parent[10][10];
    string s[10],p;
    memset(parent,0,sizeof(parent));
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    q.push(pii(x,y));

    level[x][y]=0;
    vis[x][y]=1;
    parent[x][y]=pii(x,y);
//    s[x][y]="s";

    int max=0;
    while(!q.empty()){
        pii top=q.front();q.pop();

        int sx,sy,tx,ty;
        sx=top.first;sy=top.second;
        if(sx==dex and sy==dey){
            max=level[sx][sy];
           break;
        }
        ///R move
        tx=sx;ty=sy+1;
       // cout<<tx<<' '<<ty<<endl;
        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='R';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
        ///L move
        tx=sx;ty=sy-1;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='L';
            parent[tx][ty]=pii(sx,sy);
           // cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
        ///U move
        tx=sx+1;ty=sy;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='U';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
        ///D move
        tx=sx-1;ty=sy;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='D';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
        ///RU move
        tx=sx-1;ty=sy+1;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='A';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
         ///RD move
        tx=sx+1;ty=sy+1;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='B';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
         ///LU move
        tx=sx-1;ty=sy-1;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='C';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
         ///LD move
        tx=sx+1;ty=sy-1;

        if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0){
            level[tx][ty]=level[sx][sy]+1;
            vis[tx][ty]=1;
            s[tx][ty]='e';
            parent[tx][ty]=pii(sx,sy);
            //cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<' '<<s[tx][ty]<<endl;
            q.push(pii(tx,ty));
        }
    }
    max=level[dex][dey];
    cout<<max<<endl;
    int u,v,t=0;

    u=dex;v=dey;
    while(1){
        if(u==srx and v==sry)
            break;
        p+=s[u][v];
        if(s[u][v]=='A')cout<<"RD"<<endl;
        else if(s[u][v]=='B')cout<<"RU"<<endl;
        else if(s[u][v]=='C')cout<<"LD"<<endl;
        else if(s[u][v]=='e')cout<<"LU"<<endl;
        else cout<<s[u][v]<<endl;
        u=parent[u][v].first;v=parent[u][v].second;
        //cout<<u<<' '<<v<<endl;
    }

    /*for(int i=p.size()-1;i>=0;i--){
        if(p[i]=='A')cout<<"RD"<<endl;
        else if(p[i]=='B')cout<<"RU"<<endl;
        else if(p[i]=='C')cout<<"LD"<<endl;
        else if(p[i]=='e')cout<<"LU"<<endl;
        else cout<<p[i]<<endl;
    }*/
}

int main()
{
    char a,b,c;
    while(cin>>a>>srx>>b>>dex){
        sry=a-96;dey=b-96;
       // cout<<srx<<' '<<sry<<' '<<dex<<' '<<dey<<endl;
        bfs(srx,sry);
    }
}
