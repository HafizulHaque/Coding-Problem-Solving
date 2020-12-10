#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
vector<int>edges[100];
map <char, int> nodes;
int vis[1000];
int bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0; i<edges[u].size(); i++){
            int v=edges[u][i];
            if(vis[v]==0){
                vis[v]=1;
                q.push(v);
            }
        }
    }
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
        char ch,a,b;
        string s,s1;
        cin>>s1;
        getchar();
         int count1=s1[0]-'0'-16;
        //getline(cin,s);
        int x=0;
        memset(vis,0,sizeof(vis));
        nodes.clear();
        for(int i=0;i<100;i++)
            edges[i].clear();
        if(o==t){
            while(getline(cin,s)){
            a=s[0],b=s[1];
            if(nodes[a]==0){
                nodes[a]=++x;
            }
            if(nodes[b]==0){
                nodes[b]=++x;
            }
            edges[nodes[a]].push_back(nodes[b]);
            edges[nodes[b]].push_back(nodes[a]);
        }
        int count=0;
        for(int i=1;i<=count1;i++){
            if(vis[i]==0){
                bfs(i);
                count++;
            }
        }
            cout<<count<<endl;
        }
        else{
            while(getline(cin,s)){
            int y=s.length();
            if(y==0)
                break;
            a=s[0],b=s[1];
            if(nodes[a]==0){
                nodes[a]=++x;
            }
            if(nodes[b]==0){
                nodes[b]=++x;
            }
            edges[nodes[a]].push_back(nodes[b]);
            edges[nodes[b]].push_back(nodes[a]);
        }
        int count=0;
        for(int i=1;i<=count1;i++){
            if(vis[i]==0){
                bfs(i);
                count++;
            }
        }
        cout<<count<<endl;
        }

    }
}
