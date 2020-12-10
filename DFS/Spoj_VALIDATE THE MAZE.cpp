#include<bits/stdc++.h>
using namespace std;
#define clean(a,b) memset(a,0,sizeof(a))
int fx[]={0,1,0,-1};
int fy[]={-1,0,1,0};

char ara[22][22];
int vis[22][22];
int r,c,count=0;
int dfs(int x1,int y1,int x2,int y2)
{
     cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    if(x1==x2 and y1==y2)
        return 1;

    vis[x1][y1]=1;
    int sum=0;

    for(int k=0;k<4;k++){
        int xx=x1+fx[k];
        int yy=y1+fy[k];

         if(xx<0 or xx>=r or yy<0 or yy>=c ) continue;
         if(vis[xx][yy]) continue;
         if(ara[xx][yy]=='#') continue;
         if(ara[xx][yy]=='.'){
            sum=max(sum,dfs(xx,yy,x2,y2));
         }
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
            clean(vis,0);
        scanf("%d%d",&r,&c);
        getchar();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%c",&ara[i][j]);
            }
            getchar();
        }
        int x1,y1,x2,y2,count=0;

        for(int i=0;i<1;i++){
            for(int j=0;j<c;j++){
                cout<<i<<' '<<j<<' '<<ara[i][j]<<endl;
                if(ara[i][j]=='.'){
                    count++;
                    if(count==1){
                        x1=i,y1=j;
                    }
                    if(count==2){
                         x2=i,y2=j;
                    }
                }
            }
        }

        for(int i=r-1;i<r;i++){
            for(int j=0;j<c;j++){
                 cout<<i<<' '<<j<<' '<<ara[i][j]<<endl;
                if(ara[i][j]=='.'){
                    count++;
                    if(count==1){
                        x1=i,y1=j;
                    }
                    if(count==2){
                         x2=i,y2=j;
                    }
                }
            }
        }


        for(int i=0;i<1;i++){
            for(int j=0;j<r;j++){
                //cout<<i<<' '<<j<<' '<<ara[i][j]<<endl;
                if(ara[j][i]=='.'){
                    count++;
                    if(count==1){
                        x1=j,y1=i;
                    }
                    if(count==2){
                         x2=j,y2=i;
                    }
                }
            }
        }

        for(int i=c-1;i<c;i++){
            for(int j=0;j<r;j++){
                //cout<<i<<' '<<j<<' '<<ara[i][j]<<endl;
                if(ara[j][i]=='.'){
                    count++;
                    if(count==1){
                        x1=j,y1=i;
                    }
                    if(count==2){
                         x2=j,y2=i;
                    }
                }
            }
        }
        cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<count<<endl;
        if(count>2 or count<2) printf("invalid\n");
        else if(dfs(x1,y1,x2,y2))printf("valid\n");
        else printf("invalid\n");
    }
}
