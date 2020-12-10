#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
string ara[30];
int fx[]={1,-1,0,0,1,-1,-1,1};
int fy[]={0,0,1,-1,1,-1,1,-1};
int vis[30][30];
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
                if(tx>=0 and tx<x and ty>=0 and ty<y and ara[tx][ty]=='1' and vis[tx][ty]==0)
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
    //getchar();
    for(int o=1;o<=t;o++){
        if(o>1)
            cout<<endl;
        int i=0,l,m,n,count=0;
        memset(vis,0,sizeof(vis));
        string s;
        if (o==t){
            while(getline(cin,s)){
            int x=s.length();
            ara[i]=s;
            if(i==0)
                l=x;
            i++;
            }
            for(int k=0;k<i;k++){
                for(int j=0;j<l;j++){
                    if(ara[k][j]=='1' and vis[k][j]==0){
                        int z=bfs(k,j,i,l);
                        if(z>count)
                            count=z;
                    }
                }
            }
            cout<<count<<endl;
        }
        else{
                i=0;
        while(getline(cin,s)){
            int x=s.length();
            if(x==0){
                for(int k=0;k<i;k++){
                    for(int j=0;j<l;j++){
                        if(ara[k][j]=='1' and vis[k][j]==0){
                            int z=bfs(k,j,i,l);
                            if(z>count)
                                count=z;
                        }
                    }
                }
                cout<<count<<endl;
                break;
            }
            if(s[0]=='1'||s[0]=='0'){
                ara[i]=s;
                if(i==0)
                    l=x;
                i++;
            }
        }
        }

    }

}
