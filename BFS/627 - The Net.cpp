#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>

using namespace std;

vector<int>edges[310];

int bfs(int src,int b)
{
    queue<int>q;
    q.push(src);
    int visited[310]={0},level[310]={0};
    int parent[310]={0};
    visited[src]=1;
    parent[src]=src;
    level[src]=0;
    int flag=0;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(v==b){
                if(parent[v]==0){
                    level[v]=level[u]+1;
                    parent[v]=u;
                }
                else if(u<parent[v]&&level[u]<level[v]){
                    parent[v]=u;
                    level[v]=level[u]+1;
                }
                    flag=1;
            }
            else if(visited[v]==0){
                level[v]=level[u]+1;
                visited[v]=1;
                parent[v]=u;
                q.push(v);
            }
        }
        q.pop();
    }

    if(flag==0){
        cout<<"connection impossible"<<endl;
    }
    else{
        int ara[310];
        int u=b;
        int i=0;
        ara[i]=u;
        i++;
        while(u!=src){
            u=parent[u];
            ara[i]=u;
            i++;
        }
        for(int j=i-1;j>=0;j--){
            if(j==0)
                cout<<ara[j]<<endl;
            else
                cout<<ara[j]<<' ';
        }
    }
}

int main()
{
    int n;
    while(cin>>n){
        if(n==0)
            break;
        char ch;
        int x,y=0,p,q,r;
        string str;
        for(int i=1;i<=n;i++){
            cin>>str;
            for(int j=0;j<str.length();j++){
                if(str[j]=='-'){
                    int a=1,k;
                    y=0;
                    for(k=j+1;str[k]!=','&&k<str.length();k++){
                        y=y*10;
                        y+=(str[k]-'0');
                    }
                    j=k-1;
                    if(y!=0)
                    edges[i].push_back(y);
                }
                if(str[j]==','){
                    int a=1,k;
                    y=0;
                    for(k=j+1;str[k]!=','&&k<str.length();k++){
                        y=y*10;
                       y+=(str[k]-'0');
                    }
                    j=k-1;
                   if(y!=0)
                    edges[i].push_back(y);
                }

                }
            }
        int m;
        cin>>m;
        cout<<"-----"<<endl;
        for(int i=0;i<m;i++){
            cin>>p>>q;
            bfs(p,q);
        }
        for(int i=0;i<310;i++)
            edges[i].clear();
    }
}
