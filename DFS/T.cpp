#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
queue<pii>q;
char ara[505][505];
int value[505][505];
int fx[]={0,1,0,-1};
int fy[]={-1,0,1,0};

int m,n,r;

int dfs(int x,int y,int c)
{
    //cout<<x<<' '<<y<<'M'<<endl;
    ara[x][y]='#';
    int z=c;

    for(int k=0;k<4;k++){
        int xx=x+fx[k];
        int yy=y+fy[k];

        if(xx<1 or xx>m or yy<1 or yy>n) continue;
        if(ara[xx][yy]=='#') continue;
        if(ara[xx][yy]=='.'){
            z=max(z,dfs(xx,yy,z));
        }
        if(ara[xx][yy]=='C'){
            z=max(z,dfs(xx,yy,z+1));
        }
    }
    q.push(pii(x,y));
    //cout<<x<<' '<<y<<' '<<z<<endl;
    //value[x][y]=z;
    return z;
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d%d",&m,&n,&r);
        getchar();

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%c",&ara[i][j]);
            }
            getchar();
        }

        memset(value,0,sizeof(value));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(ara[i][j]=='.'){
                    value[i][j]=dfs(i,j,0);
                    while(!q.empty()){
                        pii top=q.front();
                        int z=top.first;
                        int o=top.second;
                    //cout<<z<<' '<<o<<' '<<value[i][j]<<endl;
                        value[z][o]=value[i][j];
                        q.pop();
                    }

                }
            }
        }

        printf("Case %d:\n",++cas);
        int x,y;
        for(int i=1;i<=r;i++){
            scanf("%d%d",&x,&y);

            printf("%d\n",value[x][y]);
        }
    }
}
