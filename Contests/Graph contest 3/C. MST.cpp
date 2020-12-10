#include <bits/stdc++.h>
using namespace std;
#define N 102

typedef struct edge{
    int a, b;
    double w;
    bool operator <(const edge &x)const{
        return w < x.w;
    }
};

vector<edge> e;
int parent[N+1];

void addEdge(int p, int q, double weight){
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

double kruscal_mst(int n){
    sort(e.begin(), e.end());   // sort edges according to cost
    for(int i = 1; i <= n; ++i)
        parent[i] = i;          // setting parent initially

    int count = 0;
    double total_cost = 0;

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
    //FILE *inp = freopen("C.txt", "r", stdin);

    int test;
    cin>>test;
    for(int t = 0; t < test; ++t){
        int n;
        cin>>n;
        cout<<fixed;
        cout<<setprecision(2);
        e.clear();
        for(int i = 0; i < 102; ++i)
            parent[i] = 0;

        double x[n], y[n];
        for(int i = 0; i < n; ++i)
            cin>>x[i]>>y[i];

        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j){
                addEdge(i+1, j+1, sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2)));
            }
        }
        if(t) cout << "\n";
        cout<<kruscal_mst(n)<< "\n";
    }

    //fclose(inp);
    return 0;
}

