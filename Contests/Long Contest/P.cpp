// accepted

#include <bits/stdc++.h>
using namespace std;
int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    int cap = 0, small = 0;
    scanf("%d\n", &n);
    char str[2*n+2];
    int index[2*n+1];
    scanf("%s", str);
    for(int i = 0; i < 2*n; ++i){
        if(islower(str[i])) index[i] = ++small;
        else if(isupper(str[i])) index[i] = ++cap;
    }
    stack<pair<int,char> >st;
    map<int, int> res;
    for(int i = 0; i < 2*n; ++i){
        if(st.empty()) st.push(make_pair(index[i],str[i]));
        else{
            if(abs((int)st.top().second-(int)str[i])==32){
                if(isupper(str[i])) res.insert(make_pair(index[i], st.top().first));
                else res.insert(make_pair(st.top().first,index[i]));
                st.pop();
            }
            else st.push(make_pair(index[i],str[i]));
        }
    }
    if(!st.empty()){
        cout << "Impossible" << endl;
    }
    else{
        for(auto itr = res.begin(); itr != res.end(); ++itr){
            cout << itr->second << " ";
        }
        cout << endl;
    }
    //fclose(inp);
    return 0;
}
