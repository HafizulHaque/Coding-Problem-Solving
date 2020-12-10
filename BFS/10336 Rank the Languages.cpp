#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#define pii pair<int,int>
using namespace std;
char ara[110][110];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int vis[110][110];
int m,n;
int bfs(int sx,int sy,char src)
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
                if(tx>=0 and tx<m and ty>=0 and ty<n and ara[tx][ty]==src and vis[tx][ty]==0)
                {
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
    for(int o=1;o<=t;o++){
        cin>>m>>n;
        map <char, int> nodes;
        vector<char>v;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              cin>>ara[i][j];
              if(nodes[ara[i][j]]==0){
                v.push_back(ara[i][j]);
                nodes[ara[i][j]]++;
              }
            }
        }
        int count=0,c=0;
        int my[v.size()+1];
        char my1[v.size()+1];
        for(int p=0;p<v.size();p++){
                count=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(ara[i][j]==v[p]&&vis[i][j]==0){
                        bfs(i,j,v[p]);
                        count++;
                    }
                }
            }
            my[c]=count;
            my1[c]=v[p];
            c++;
        }
        int temp;
        char tmp;
        for(int i=0;i<c-1;i++){
            for(int j=i+1;j<c;j++){
                if(my[i]<my[j]){
                    swap(my[i],my[j]);
                    swap(my1[i],my1[j]);
                }
                else if(my[i]==my[j]){
                    if(my1[i]>my1[j]){
                        swap(my1[i],my1[j]);
                    }
                }
            }
        }
        cout<<"World #"<<o<<endl;
        for(int i=0;i<c;i++)
            cout<<my1[i]<<": "<<my[i]<<endl;
    }
}
