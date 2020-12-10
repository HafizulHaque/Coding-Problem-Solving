#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
string ara[210];
int fx[]={1,-1,0,0,1,-1,-1,1};
int fy[]={0,0,1,-1,1,-1,1,-1};
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
           for(int k=0;k<8;k++){
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(tx>=0 and tx<x and ty>=0 and ty<y and ara[tx][ty]=='W' and vis[tx][ty]==0)
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
        int i=0,l,m,n;
        string s;
        if (o==t){
            while(getline(cin,s)){
            int x=s.length();
            if(s[0]=='L'||s[0]=='W'){
                ara[i]=s;
                if(i==0)
                    l=x;
                i++;
            }
            else if(s[0]>='1'&&s[0]<='9'){
                 memset(vis,0,sizeof(vis));
                sscanf(s.c_str(),"%d%d",&m,&n);
                cout<<bfs(m-1,n-1,i,l)<<endl;
            }
        }
        }
        else{
             while(getline(cin,s)){
            int x=s.length();
            if(x==0)
                break;
            if(s[0]=='L'||s[0]=='W'){
                ara[i]=s;
                if(i==0)
                    l=x;
                i++;
            }
            else if(s[0]>='1'&&s[0]<='9'){
                 memset(vis,0,sizeof(vis));
                sscanf(s.c_str(),"%d%d",&m,&n);
                cout<<bfs(m-1,n-1,i,l)<<endl;
            }
        }
        }

    }

}
