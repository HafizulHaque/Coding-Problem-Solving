// accepted

#include <bits/stdc++.h>
using namespace std;
#define psi pair<string, int>
int main(){
    queue<psi> schedule_queue;
    int n, time, quantam, current_time = 0;
    string name;
    cin>>n>>quantam;
    for(int i = 0; i < n; ++i){
        cin>>name>>time;
        schedule_queue.push(make_pair(name, time));
    }
    while(!schedule_queue.empty()){
        psi item = schedule_queue.front();
        schedule_queue.pop();
        if(item.second>quantam){
            current_time += quantam;
            schedule_queue.push(make_pair(item.first, item.second-quantam));
        }
        else{
            current_time += item.second;
            cout << item.first << " " << current_time << endl;
        }
    }
    return 0;
}
