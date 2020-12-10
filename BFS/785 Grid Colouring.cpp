#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
string ara[50];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int vis[50][100];
int bfs(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=1;

    while(!q.empty())
	{
		pii top=q.front(); q.pop();
           for(int k=0;k<4;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(vis[tx][ty]==0 and ara[tx][ty]==' ')
                {
                    ara[tx][ty]=ara[sx][sy];
                    vis[tx][ty]=1;
                    q.push(pii(tx,ty));
                }
            }
    }
}

int main()
{
        string s;
        int ara1[50],m[2500],n[2500];
        int flag=0,i=0,x,k=0;
        memset(vis,0,sizeof(vis));
       while(getline(cin,s)){
            if(s[0]=='_'){
                for(int o=0;o<k;o++)
                    bfs(m[o],n[o]);

                for(int j=0;j<i;j++){
                    for(int d=0;d<ara1[j];d++)
                        cout<<ara[j][d];
                        cout<<endl;
                }
                cout<<s<<endl;
                //int ara1[50],m[2500],n[2500];
                memset(ara1,0,sizeof(ara1));
                memset(m,0,sizeof(m));
                memset(n,0,sizeof(n));
                memset(vis,0,sizeof(vis));
                i=0,x=0,k=0;
            }
            else{
                x=s.size();
                ara[i]=s;
                ara1[i]=x;
                for(int l=0;l<x;l++){
                    if(ara[i][l]!=' '&&(ara[i][l]<'A'||ara[i][l]>'Z')&&(ara[i][l]<'a'||ara[i][l]>'z')){
                        m[k]=i;
                        n[k]=l;
                        k++;
                    }
                }
                i++;
            }
       }
return 0;
}
