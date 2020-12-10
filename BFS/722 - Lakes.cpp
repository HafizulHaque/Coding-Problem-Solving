#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
string ara[110];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int vis[110][110];
int bfs(int sx,int sy,int x,int y)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    int count=1;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<4;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<x and ty>=0 and ty<y and ara[tx][ty]=='0' and vis[tx][ty]==0)
                {
                    count++;
                    vis[tx][ty]=1;
                    q.push(pii(tx,ty));
                }
            }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    getchar();
    getchar();
    for(int o=1;o<=t;o++){
        if(o>1)
            cout<<endl;
        int m,n,l;
        string s;
        cin>>m>>n;
        getchar();
        if (o==t){
            int i=0;
            while(getline(cin,s)){
            int x=s.length();
                ara[i]=s;
                if(i==0)
                    l=x;
                i++;
            }
            memset(vis,0,sizeof(vis));
            int z=bfs(m-1,n-1,i,l);
                if(z==0)
                    z=1;
            cout<<z<<endl;
        }
        else{
            int i=0;
             while(getline(cin,s)){
                int x=s.length();
                if(x==0)
                    break;
                ara[i]=s;
                if(i==0)
                    l=x;
                i++;
            }
                memset(vis,0,sizeof(vis));
                int z=bfs(m-1,n-1,i,l);
                if(z==0)
                    z=1;
            cout<<z<<endl;
        }
    }
}
