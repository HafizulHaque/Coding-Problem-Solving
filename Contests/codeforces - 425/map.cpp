#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> phonebook;
    string name;
    int phn_no;
    string query;
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s%d\n", &name, &phn_no);
        phonebook.insert(make_pair(name, phn_no));
    }
    while(scanf("%s", &query)!=NULL){
        pair<string, int> output;
        output = find(phonebook.begin(), phonebook.end(), query);
        if(query != phonebook.end()){
            cout<<query.first<<"="<<query.second<<endl;
        }
    }
}
