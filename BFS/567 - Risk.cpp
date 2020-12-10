#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

vector<int>edges[25];
int bfs(int src,int n)
{
	queue<int>q;
	q.push(src);
	int visited[25]={0},level[25];
	visited[src]=1;
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
	if(src<10&&n<10){
        printf(" %d to  %d: %d\n",src,n,level[n]);
	}
	else if(src>=10&&n<10){
        printf("%d to  %d: %d\n",src,n,level[n]);
	}
	else if(src<10&&n>=10){
        printf(" %d to %d: %d\n",src,n,level[n]);
	}
	else if(src>=10&&n>=10){
        printf("%d to %d: %d\n",src,n,level[n]);
	}
}

int main()
{
    int n,x,z=1;
    while(cin>>n){
        int k=1,y;
        for(int i=0;i<n;i++){
            cin>>x;
            edges[k].push_back(x);
            edges[x].push_back(k);
        }
        k++;
        while(k<=19){
                cin>>n;
            for(int i=0;i<n;i++){
                cin>>x;
                edges[k].push_back(x);
                edges[x].push_back(k);
            }
            k++;
        }
       cin>>n;
       cout<<"Test Set #"<<z<<endl;

       for(int i=1;i<=n;i++){
            cin>>x>>y;
            bfs(x,y);
       }
       cout<<endl;
       z++;
       for(int i=0;i<25;i++)edges[i].clear();
    }
    return 0;
}
