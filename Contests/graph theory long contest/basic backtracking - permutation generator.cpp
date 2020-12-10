#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2 , 3, 4, 5, 6, 7};
vector<int>adj[8];

stack<int> st;

add_edge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main(){
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 4);
    add_edge(2, 5);
    add_edge(3, 6);
    add_edge(3, 7);

    int taken[8] = {0};
    s.push(1);

    while(!s.empty()){
        int x = s.top();
        s.pop();
    }





    return 0;
}
