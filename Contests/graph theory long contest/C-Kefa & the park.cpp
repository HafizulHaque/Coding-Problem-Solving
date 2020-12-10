#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];
    int cat_presence[n];
    int visited[n];
    vector<int> edge[n];
    stack<int>st;
    for(int i = 0; i < n; ++i) cin>>cat_presence[i];
    int x, y;
    for(int i = 1; i <= n-1; ++i){
        cin>>x>>y;
        edge[x-1].push_back(y-1);
        edge[y-1].push_back(x-1);
    }
    for(int i = 0; i < n; ++i) visited[i] = 0;

    int res = 0;
    int catcount = 0;

    st.push(0);
    while(!st.empty()){
        int s = st.top();
        st.pop();
        if(cat_presence[s]==1){
            if(++catcount>m) continue;
        }
        if(!visited[s]) visited[s] = 1;
        int mark = 0;
        for(auto itr = adj[s].begin(); itr != adj[s].end(); itr++){
            if(!visited[*itr]){
                 st.push(*itr);
                 mark = 1;
            }
        }
        if(!mark){
            res++;
            visited[s] = 0;
        }
    }
    cout << res << endl;
    fclose(inp);
    return 0;
}
