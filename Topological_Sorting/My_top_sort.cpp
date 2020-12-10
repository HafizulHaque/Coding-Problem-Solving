#include<bits/stdc++.h>
using namespace std;

vector<int>v;
queue<int>q;
int ara[110][110];
int indeg[110];
int node,edge;

void find_zero()
{
    //cout<<'f'<<endl;
    for(int i=1;i<=node;i++){
        if(indeg[i]==0)q.push(i);
    }
}

void top_sort()
{
    int a;
    while(!q.empty())
    {
        a=q.front();
       // cout<<a<<endl;
        q.pop();
        v.push_back(a);

        for(int i=1;i<=node;i++){
            if(ara[a][i]==1){
                indeg[i]--;
                if(indeg[i]==0)q.push(i);
            }
        }
    }
    cout<<"Topological Sort"<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
        cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>node>>edge;
        int u,w;
        memset(ara,0,sizeof(ara));
        memset(indeg,0,sizeof(indeg));

        for(int i=1;i<=edge;i++){
            cin>>u>>w;
            ara[u][w]=1;
            indeg[w]++;
        }
        find_zero();
        top_sort();
        v.clear();
    }
   return 0;
}
