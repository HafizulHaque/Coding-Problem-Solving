#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
char ara[210][210];
int fx[]={1,-1,0,0,1,-1};
int fy[]={0,0,1,-1,1,-1};

int bfs(int sx,int sy,int n)
{
    int vis[210][210];
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    int flag=0;
    int i=1;
    while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<6;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 and tx<n and ty>=0 and ty<n and ara[tx][ty]=='b' and vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				if(tx==n-1){
                    flag=1;
                    break;
				}
				q.push(pii(tx,ty));
			}
		}
		if(flag==1)
            break;
	}
	return flag;

}
int main()
{
    int n,o=1;
    while(cin>>n&&n!=0){
        vector<int>sx;
        vector<int>sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ara[i][j];
                if(ara[i][j]=='b'&&i==0){
                    sx.push_back(i);
                    sy.push_back(j);
                }
            }
        }
        if(sx.size()==0)
            cout<<o<<" W"<<endl;
        else{
            int flag1=0;
            for(int i=0;i<sx.size();i++){
               int z=bfs(sx[i],sy[i],n);
               if(z==1){
                flag1=1;
                break;
               }
            }
            if(flag1==0)
               cout<<o<<" W"<<endl;
            else
               cout<<o<<" B"<<endl;
        }
        o++;
    }
    return 0;
}
