#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int>edges[50];

int bfs(int src,int b,int c)
{
    queue<int>q;
    q.push(src);
    int visited[50]={0},level[50];
    visited[src]=1;
    level[src]=0;
    int count1=0,f=0;
    while(!q.empty()){
        int u=q.front();
        f++;
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(visited[v]==0){
                level[v]=level[u]+1;
                if(level[v]>b)
                    count1++;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    return count1+(c-f);
}
int main()
{
    int k=1;
    while(1){
        long int n,x,y,p,q,r,s;

        cin>>n;
        if(n==0)
            break;
        for(int i=0; i<50; i++) edges[i].clear();
        vector<int>m;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            int flag=0,flag1=0;
            for(int j=0;j<m.size();j++){
                if(m[j]==x){
                    p=j;
                    flag=1;
                }
                if(m[j]==y){
                   q=j;
                   flag1=1;
                }
                if(flag==1&&flag1==1)
                    break;
            }
            if(flag==0&&flag1==0&&x!=y){
                m.push_back(x);
                m.push_back(y);
                p=m.size()-2;
                q=m.size()-1;
            }
            else if(flag==0&&flag1==0&&x==y){
                m.push_back(x);
                p=m.size()-1;
                q=m.size()-1;
            }
            else if(flag1==1&&flag==0){
                m.push_back(x);
                p=m.size()-1;
            }
            else if(flag==1&&flag1==0){
                m.push_back(y);
                q=m.size()-1;
            }
            edges[p].push_back(q);
            edges[q].push_back(p);
        }
        int j=0;
        int flag=0;
        while(cin>>r>>s){
                flag=0;
            if(r==0&&s==0)
                break;
            for(j=0;j<m.size();j++){
                if(r==m[j]){
                    flag=1;
                    break;
                }
            }
            int z,b=m.size();
            if(flag==0){
                 z=m.size();
            }
            else{
                 z=bfs(j,s,b);
            }
            printf("Case %d: %d nodes not reachable from node %ld with TTL = %ld.\n",k,z,r,s);
            k++;
        }
    }
}
