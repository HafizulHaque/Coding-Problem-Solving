#include <bits/stdc++.h>
using namespace std;
#define N 6

int main(){
    FILE *inp = freopen("inp.txt", "r", stdin);
    FILE *out = freopen("out.txt", "w", stdout);
    vector<int>edge[N];
    vector<int>cost[N];

    int outdegree[N];
    memset(outdegree, 0, sizeof(outdegree));
    int x, y, c;// x to y directed edge, cost

    while(scanf("%d%d%d", &x, &y, &c)==3){
        edge[x].push_back(y);
        cost[x].push_back(c);
    }

    for(int i = 0; i < N; ++i){
        printf("Node %d  :   outdegree %d     edges are : ", i, edge[i].size());
        for(int j = 0; j < edge[i].size(); ++j){
            printf("%d  ", edge[i].at(j));
            outdegree[edge[i].at(j)]++;
        }
        printf("\n");
    }
    for(int i = 0; i < N; ++i)
        printf("indegree of %d  : %d\n", i, outdegree[i]);
    fclose(inp);
    fclose(out);
    return 0;
}
