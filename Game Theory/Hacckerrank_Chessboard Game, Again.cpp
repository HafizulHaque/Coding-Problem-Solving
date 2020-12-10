#include<bits/stdc++.h>
using namespace std;

int dx[]={-2,-2,1,-1};
int dy[]={1,-1,-2,-2};

int ara[20][20];

int grundy(int x,int y)
{
    if(ara[x][y]!=-1)return ara[x][y];
    set<int>s;
    set<int>::iterator it;

    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(xx>0 and xx<=15 and yy>0 and yy<=15){
            int a=grundy(xx,yy);
            s.insert(a);
        }
    }
    int k=0;
    for(it=s.begin();it!=s.end();it++){
        if(*it!=k)break;
        k++;
    }
    return ara[x][y]=k;
}
int main()
{
    memset(ara,-1,sizeof(ara));
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            grundy(i,j);
        }
    }

   int t,k,x,y,v;
   cin>>t;
   while(t--){
        v=0;
        scanf("%d",&k);
        while(k--){
            scanf("%d %d",&x,&y);
            v^=ara[x][y];
        }
        if(v>0)printf("First\n");
        else printf("Second\n");
   }
}
