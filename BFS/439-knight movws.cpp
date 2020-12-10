#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
int fx[]={-1,-2,-1,-2,1,2,1,2};
int fy[]={-2,-1,2,1,-2,-1,2,1};
int vis[8][8];
string s1,s2;
int bfs(int sx,int sy,int x,int y)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    int d[8][8];
    vis[sx][sy]=1;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            d[i][j]=1000000;
    }

    d[sx][sy]=0;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
            int cost=d[top.first][top.second];
           for(int k=0;k<8;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<8 and ty>=0 and ty<8 and cost+1<d[tx][ty] and vis[tx][ty]==0)
                {
                    d[tx][ty]=cost+1;
                    q.push(pii(tx,ty));
                }
            }
    }
   int z=d[x][y];
    cout<<"To get from "<< s1 <<" to "<< s2 <<" takes "<< z<<" knight moves."<<endl;
}
int main()
{
    string s="abcdefgh";
    while(cin>>s1>>s2){
        int m,n,p,q;
        memset(vis,0,sizeof(vis));

        for(int i=0;i<8;i++){
            if(s1[0]==s[i]){
                m=i;
                n=s1[1]-'0';
            }
        }

        for(int i=0;i<8;i++){
            if(s2[0]==s[i]){
                p=i;
                q=s2[1]-'0';
            }
        }
        bfs(m,n-1,p,q-1);
    }

}
