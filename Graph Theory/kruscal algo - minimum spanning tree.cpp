#include <bits/stdc++.h>
using namespace std;
#define N 100

typedef struct edge{
    int a, b, w;
    bool operator <(const edge &x)const{
        return w < x.w;
    }
};

vector<edge> e;
int parent[N+1];

void addEdge(int p, int q, int weight){
    edge x;
    x.a = p;
    x.b = q;
    x.w = weight;
    e.push_back(x);
 }


int find(int n){
    int a = parent[n]==n? n : find(parent[parent[n]]);
    parent[n] = a;
    return a;
}

int kruscal_mst(int n){
    sort(e.begin(), e.end());   // sort edges according to cost
    for(int i = 1; i <= n; ++i)
        parent[i] = i;          // setting parent initially

    int count = 0, total_cost = 0;

    for(int i = 0; i < (int)e.size(); ++i){
        int u = find(e[i].a);
        int v = find(e[i].b);

        if(u!=v){
            parent[u] = v;
            count++;
            total_cost += e[i].w;
            if(count == n-1)
                break;
        }
    }
    return total_cost;
}


int main(void){
    FILE *inp = freopen("kruscal_inp.txt", "r", stdin);
    int a, b, w;
    while(scanf("%d%d%d", &a, &b, &w)==3){
        addEdge(a, b, w);
    }

    cout << "minimum spanning cost "<< kruscal_mst(7) << endl;
    fclose(inp);
    return 0;
}

