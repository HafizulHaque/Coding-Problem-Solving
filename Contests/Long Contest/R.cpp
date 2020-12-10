// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int year, n, r, printed = 0;
    string full_desc, univ_name;
    string delimiter = " #";
    set<string>_list;
    scanf("%d%d%d\n", &year, &n, &r);
    for(int i = 0; i < n; ++i){
        getline(cin,full_desc);
        univ_name = full_desc.substr(0, full_desc.find(delimiter));
        _list.insert(univ_name);
        if(_list.size()==r+1&&printed==0){
            cout << full_desc << endl;
            printed = 1;
        }
    }
    //fclose(inp);
    return 0;
}
