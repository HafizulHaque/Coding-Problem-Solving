// accepted

#include <bits/stdc++.h>
using namespace std;

typedef struct Team{
    int solved;
    int penalty;
    bool operator ==(const Team &t)const{
        return solved==t.solved&&penalty==t.penalty;
    }
    bool operator >(const Team &t)const{
        return solved>t.solved||(solved==t.solved&&penalty<t.penalty);
    }
};

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n, q, sol, pen, cnt = 1;
    cin>>n>>q;
    Team teams[n+1];
    for(int i = 1; i <= n; ++i){
        cin>>teams[i].solved>>teams[i].penalty;
    }
    sort(teams+1, teams+(n+1), greater<Team>());
    for(int i = 1; q-i>=1||q+i<=n ; ++i){
        if(q-i>=1&&teams[q]==teams[q-i]) cnt++;
        if(q+i<=n&&teams[q]==teams[q+i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
