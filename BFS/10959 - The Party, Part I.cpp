#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
vector<int>edges[1010];
int bfs(int src,int b)
{
    queue<int>q;
	q.push(src);
	int visited[1010]={0},level[1010];
	visited[src]=1;
	memset(level,0,sizeof(level));
    level[src]=0;
	while(!q.empty())
	{
		int u=q.front();
		for(int i=0;i<edges[u].size();i++)
		{
			int v=edges[u][i];
			if(!visited[v])
			{
				level[v]=level[u]+1;
				visited[v]=1;
				q.push(v);
			}
		}
		q.pop();
	}
	for(int i=1;i<b;i++){
        if(level[i]==0)
            cout<<-1<<endl;
        else
          cout<<level[i]<<endl;
	}

}
int main()
{
    int t;
    cin>>t;

    for(int o=1;o<=t;o++){
        int p,d,x,y;
        if(o>1)
            cout<<endl;
        cin>>p>>d;
        for(int i=1;i<=d;i++){
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        bfs(0,p);
        for(int i=0;i<1010;i++)
        edges[i].clear();
    }
}
