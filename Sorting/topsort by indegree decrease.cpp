#include <bits/stdc++.h>
using namespace std;
#define N 10

typedef struct node{
    int x;
    int indegree;
    vector<int>outdegrees;

    bool operator <(const node &w)const{
        if(indegree < w.indegree)
            return true;
        else if(indegree==w.indegree){
            return x<w.x;
        }
        else
            return false;
    }
};

int main(){
    FILE *inp = freopen("topsort.txt", "r", stdin);
    node nodes[N];

    for(int i = 0; i < N; ++i){
        nodes[i].x = i;
        nodes[i].indegree = 0;
        nodes[i].outdegrees.clear();
    }

    int a, b;
    while(scanf("%d%d", &a, &b)==2){
        nodes[a].outdegrees.push_back(b);
        nodes[b].indegree++;
    }


    for(int i = 0; i < N; ++i){
        sort(nodes+i, nodes+N);
        if(i!=0)printf(" --> ");
        printf("%d", nodes[i].x);
        for(auto itr = nodes[i].outdegrees.begin(); itr != nodes[i].outdegrees.end(); ++itr){
            nodes[*itr].indegree--;
        }
    }

    fclose(inp);
}
