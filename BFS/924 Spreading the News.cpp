#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
vector<int>edges[2600];
int bfs(int src,int b)
{
    queue<int>q;
    q.push(src);
    int visited[2600]={0},level[2600]={0};
    visited[src]=1;
    level[src]=0;
    int flag=0;
    int m,d,count,count1=0,max=0;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];

            if(visited[v]==0){
                level[v]=level[u]+1;
                visited[v]=1;
                q.push(v);
                max=level[v];
            }
        }
        q.pop();
    }
    int j;
    for(int i=1;i<=max;i++){
            count=0;
        for(j=0;j<b;j++){
            if(level[j]==i){
                count++;
            }
        }
        if(count>count1){
            count1=count;
            d=i;
        }
    }

    if(count1==0){
        cout<<0<<endl;
    }
    else{
      cout<<count1<<' '<<d<<endl;
    }
}
int main()
{
    int e;
    cin>>e;
    int n,x,y,p,q,r,s,t;

    for(int i=0;i<e;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>x;
            edges[i].push_back(x);
        }
    }
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>p;
        bfs(p,e);
    }
}
