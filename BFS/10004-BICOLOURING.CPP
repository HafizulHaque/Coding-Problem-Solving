#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int>edges[1000];
int bfs(int n,int src)
{
    //cout<<n<<' '<<src<<endl;
    int ara[n+2];
    queue<int>q;
    memset(ara,0,sizeof(ara));
    q.push(src);
    ara[src]=1;
    int flag=0;
    while(!q.empty()){
        int u=q.front();
        //cout<<u<<' '<<ara[u]<<endl;
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
          // cout<<v<<' '<<ara[v]<<endl;
            if((ara[u]==ara[v])&&(ara[u]!=0&&ara[v]!=0)){
                    flag=1;
                    break;
            }
            else if(ara[u]==1&&ara[v]==0){
                ara[v]=2;
                q.push(v);
            }
            else if(ara[u]==2&&ara[v]==0){
                ara[v]=1;
                q.push(v);
            }
            //cout<<v<<' '<<ara[v]<<endl;
        }
        if(flag==1)
            break;
        q.pop();
    }
    if(flag==1)
        cout<<"NOT BICOLORABLE."<<endl;
    else
        cout<<"BICOLORABLE."<<endl;

}
int main()
{
    int n,e,i,x,y,m,m1=1000,m2;
    while(1){
        cin>>n;
        if(n==0)
            break;
        cin>>e;
        for(int i=0; i<1000; i++) edges[i].clear();
        for(int i=1;i<=e;i++){
            cin>>x>>y;
            m=min(x,y);
            edges[x].push_back(y);
            edges[y].push_back(x);
            m2=min(m,m1);
            if(m<m1)
                m1=m;
        }
        bfs(n,m2);
    }
   return 0;
}

