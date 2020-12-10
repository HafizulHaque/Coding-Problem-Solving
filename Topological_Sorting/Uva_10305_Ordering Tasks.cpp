#include<bits/stdc++.h>
using namespace std;
#define max 110

vector<int>v;
queue<int>q;
int ara[max][max];
int indeg[max];
int node,edge;

void find_zero()
{
    for(int i=1;i<=node;i++){
        if(indeg[i]==0)q.push(i);
    }
}

void top_sort()
{
    int a;

    while(!q.empty())
    {
        a=q.front();q.pop();
        v.push_back(a);
        for(int i=1;i<=node;i++){
            if(ara[a][i]==1){
                indeg[i]--;
                if(indeg[i]==0)q.push(i);
            }
        }
    }

    for(int i=0;i<v.size();i++){
        if(i==v.size()-1)cout<<v[i]<<endl;
        else cout<<v[i]<<' ';
    }
}

int main()
{
    while(cin>>node>>edge){
        if(node==0 and edge==0)break;
        memset(ara,0,sizeof(ara));
        memset(indeg,0,sizeof(indeg));

        int u,w;

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
