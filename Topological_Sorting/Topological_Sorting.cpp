#include<bits/stdc++.h>
using namespace std;

queue<int>x;
int parent[100];
int a[100][100];
int indeg[100];
int node;
int edge;

void collect()
{
    int i;
    int start=1;

    for(i=start; i<=node; i++)
        {
            if(indeg[i]==0)
                x.push(i);
        }
}

void topologicalsort()
{
    int i;
    int k=0;
    while(!x.empty())
        {
            int p=x.front();

            x.pop();

            parent[k++]=p;

            for(i=1; i<=node; i++)
                {
                    if(a[p][i]==1)
                        {
                            indeg[i]--;
                            if(indeg[i]==0)
                                {
                                    x.push(i);
                                }
                        }
                }
        }

    for(i=0; i<k; i++)
        {
            cout<<parent[i];
            if(i<k)
                cout<<" ";
        }
    cout<<endl;
}

int main()
{

    int i;

    scanf("%d %d", &node,&edge);
    int u,v;

    for( i=1; i<=edge; i++)
        {
            cin>>u>>v;
            a[u][v]=1;
            indeg[v]++;
        }

    collect();
    topologicalsort();

    return 0;
}

