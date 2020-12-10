#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> >q;
    q.push(100);
    q.push(50);
    q.push(150);
    q.push(100);
    q.push(10);
    q.push(140);

    while(!q.empty()){
        cout<< q.top() << endl;
        q.pop();
    }
    return 0;
}
