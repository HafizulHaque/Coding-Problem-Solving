// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("dic.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n;
    string item, cmd;
    set<string>dictionary;
    set<string>::iterator itr;
    cin>>n;
    while(n--){
        cin>>cmd>>item;
        if(cmd=="insert") dictionary.insert(item);
        else if(cmd=="find"){
            itr = dictionary.find(item);
            if(itr==dictionary.end()) cout << "no" << endl;
            else cout << "yes" << endl;
        }
    }
    //fclose(inp);
    return 0;
}
