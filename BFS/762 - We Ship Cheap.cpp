#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<cstring>
#include<ctype.h>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define read() freopen("input.txt","r",stdin)
#define write() freopen("output.txt","w",stdout)
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 100005
#define lli long long
#define pcd pair<char,double>

using namespace std;
map <string, int> nodes;
vector <string> nodes_n;
vector <int> edges[1000];
int src, dst;
void ship_cheap()
{
    int d[1000];
    bool visited[1000];
    queue <int> q;
    vector <string> net;
    int parent[1000];
    mem(d, 0); mem(visited, 0);
    mem(parent, -1);
    q.push(src);
    visited[src]=true;
    int flag=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0; i<edges[u].size(); i++){
            int v=edges[u][i];
            if(!visited[v]){
                visited[v]=true;
                d[v]=d[u]+1;
                parent[v]=u;
                q.push(v);
            }
            if(v==dst){
                flag=1; break;
            }
        }
        if(flag==1) break;
    }
    int v=dst;
    int f=0;
    while(v!=-1){
        if(v==src) f=1;
        net.push_back(nodes_n[v]);
        v=parent[v];
    }
    if(f==0) net.clear();
    reverse(net.begin(), net.end());
    if(net.size()==0)
        puts("No route");
    else{
        for(int i=0; i<net.size()-1; i++)
            cout<<net[i]<<' '<<net[i+1]<<endl;
    }
}
int main()
{
    int n, k=0;
    while(cin>>n){
        if(k++>0) cout<<endl;
        nodes.clear(); nodes_n.clear();
        nodes_n.push_back("MASUD");
        for(int i=0; i<1000; i++) edges[i].clear();
        string a, b;
        int x=0;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            if(nodes[a]==0){
                nodes[a]=++x; nodes_n.push_back(a);
            }
            if(nodes[b]==0){
                nodes[b]=++x; nodes_n.push_back(b);
            }
            edges[nodes[a]].push_back(nodes[b]);
            edges[nodes[b]].push_back(nodes[a]);
        }
        cin>>a>>b;
        src=nodes[a]; dst=nodes[b];
        if(!(src and dst)){
            puts("No route"); continue;
        }
        ship_cheap();
    }
    return 0;
}
