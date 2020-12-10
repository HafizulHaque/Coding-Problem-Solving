#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
string ara[50];
int fx[]={1,-1,0,0,1,-1,-1,1};
int fy[]={0,0,1,-1,1,-1,1,-1};
int vis[50][100];
int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;
    ara[sx][sy]='#';
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<8;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(vis[tx][ty]==0 and ara[tx][ty]==' ')
                {
                    ara[tx][ty]='#';
                    vis[tx][ty]=1;
                    q.push(pii(tx,ty));
                }
            }
    }
}

int main()
{
    int t;
    cin>>t;
    getchar();
    for(int o=1;o<=t;o++){
        string s;
        int ara1[50];
        int m,n,flag=0,i=0,x;
        memset(vis,0,sizeof(vis));
       while(getline(cin,s)){
            if(s[0]=='_')
              break;
            x=s.size();
            ara[i]=s;
            ara1[i]=x;
            for(int l=0;l<x&&flag==0;l++){
                if(ara[i][l]=='*'){
                    m=i;
                    n=l;
                    flag=1;
                    break;
                }
            }
            i++;
       }
        bfs(m,n);
        for(int j=0;j<i;j++){
            for(int d=0;d<ara1[j];d++)
                cout<<ara[j][d];
                cout<<endl;
        }
        cout<<s<<endl;
    }
return 0;
}
