#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;
vector<int>edges[1000];
int bfs(int src,int b,int c)
{
    queue<int>q;
    q.push(src);
    int visited[1000]={0},level[1000];
    visited[src]=1;
    level[src]=0;
    int flag=0;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(v==b)
                flag=1;
            if(visited[v]==0){
                level[v]=level[u]+1;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    if(flag==0){
        cout<<"NO SHIPMENT POSSIBLE"<<endl;
    }
    else{
        cout<<"$"<<level[b]*100*c<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int m,n,r;
        cin>>m>>n>>r;
        string a,b,c,d;
        vector<string>str;
        for(int i=0;i<1000;i++)
            edges[i].clear();

        for(int i=0;i<m;i++){
            cin>>a;
            str.push_back(a);
        }

        int p,q,s,flag,flag1;

        for(int i=0;i<n;i++){
            cin>>b>>c;
            flag=0,flag1=0;
            for(int j=0;j<str.size();j++){
                if(str[j]==b){
                    p=j;
                    flag=1;
                }
                if(str[j]==c){
                    q=j;
                    flag1=1;
                }
                if(flag==1&&flag1==1)
                    break;
            }
            edges[p].push_back(q);
            edges[q].push_back(p);
        }
        if(z==1){
                cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
        }
        cout<<"DATA SET  "<<z<<endl<<endl;
        for(int i=1;i<=r;i++){
            cin>>s>>b>>c;
             flag=0,flag1=0;
            for(int j=0;j<str.size();j++){
                if(str[j]==b){
                    p=j;
                    flag=1;
                }
                if(str[j]==c){
                    q=j;
                    flag1=1;
                }
                if(flag==1&&flag1==1)
                    break;
            }
            bfs(p,q,s);
        }
        cout<<endl;
        if(z==t)
            cout<<"END OF OUTPUT"<<endl;
    }
}
