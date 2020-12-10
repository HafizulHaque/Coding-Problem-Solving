#include<bits/stdc++.h>
using namespace std;

#define max 110
queue<int>q;
vector<int>v,v1;
map<string,int>s;
map<int,string>s1;
int ara[max][max];
int indeg[max];
int vis[max];
int n,m;

void find_zero()
{
    for(int i=1;i<=n;i++){
        if(indeg[i]==0 and vis[i]==0){
            q.push(i);
        }
    }
}

void top_sort()
{
    int a;

    while(!q.empty())
    {
        a=q.front();q.pop();
        vis[a]=1;
        v.push_back(a);

        for(int i=1;i<=n;i++){
            if(ara[a][i]==1){
                indeg[i]--;
            }
        }
        while(!q.empty())q.pop();
        find_zero();
    }
}

int main()
{
    int cas=0;

    while(cin>>n){

        string x,y;
        int u,w;

        memset(ara,0,sizeof(ara));
        memset(indeg,0,sizeof(indeg));
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=n;i++){
            cin>>x;
            s[x]=i;
            s1[i]=x;
        }
        cin>>m;

        for(int i=1;i<=m;i++){
            cin>>x>>y;
            //cout<<s[x]<<' '<<s[y]<<endl;
            u=s[x];
            w=s[y];

           // cout<<u<<' '<<w<<endl;
           if(ara[u][w]==0){
                ara[u][w]=1;
                indeg[w]++;
           }
        }
        //sort(indeg+1,indeg+n+1);

        find_zero();
        top_sort();

        printf("Case #%d: Dilbert should drink beverages in this order: ",++cas);
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1)cout<<s1[v[i]]<<'.'<<endl;
            else cout<<s1[v[i]]<<' ';
        }
        cout<<endl;
        v.clear(),v1.clear();
        s.clear();s1.clear();
    }
}
