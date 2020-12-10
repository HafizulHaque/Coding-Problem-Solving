#include <bits/stdc++.h>
using namespace std;
#define N 10

typedef struct node{
    vector<int>outdegrees;
    int x;
    int indegree;

    bool operator <(const node &w)const{
        return indegree<w.indegree;
    }
};

vector<int>taken;


int main(){
    FILE *inp = freopen("topsort.txt", "r", stdin);
    vector<node>nodes(N);
    for(int i = 0; i < N; ++i){
        nodes[i].x = i;
        nodes[i].indegree = 0;
        nodes[i].outdegrees.clear();
    }
    int a, b;
    while(scanf("%d%d", &a, &b)==2){
        nodes[b].indegree++;
        nodes[a].outdegrees.push_back(b);
    }

    while(!nodes.empty()){
        sort(nodes.begin(), nodes.end());
        node *ptr = nodes.begin();

    }
}
