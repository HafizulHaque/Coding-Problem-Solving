#include<bits/stdc++.h>
using namespace std;
#define clean(a,b) memset(a,0,sizeof(a))
int fx[]={0,1,0,-1};
int fy[]={-1,0,1,0};

char ara[50][50];
int vis[50][50];
int r,c,count=0;

int dfs(int x,int y,int co)
{
    //cout<<x<<' '<<y<<' '<<co<<endl;
    vis[x][y]=1;
    int z=co;
    for(int k=0;k<4;k++){
        int xx=x+fx[k];
        int yy=y+fy[k];
       // cout<<xx<<' '<<yy<<endl;
        if(xx<0 or xx>=c or yy<0 or yy>=r ) continue;
        if(vis[xx][yy]==1)continue;
        if(ara[xx][yy]=='.'){
            //cout<<xx<<' '<<yy<<ara[xx][yy]<<endl;
           z=max(z,dfs(xx,yy,z+1));
        }
    }
    //cout<<x<<' '<<y<<' '<<z<<endl;
    return z;
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        int x,y;
        scanf("%d%d",&r,&c);
        clean(vis,0);

        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                cin>>ara[i][j];
                if(ara[i][j]=='@'){
                    x=i,y=j;
                }
            }
        }
        //cout<<x<<' '<<y<<endl;
        cout<<"Case "<<++cas<<": "<<dfs(x,y,1)<<endl;
    }
}

