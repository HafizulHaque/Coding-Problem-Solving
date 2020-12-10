#include <bits/stdc++.h>
using namespace std;
stack<char>st;
char str[1003];

int main() {
    int n;
    cin>>n;

    while(n--){
        cin>>str;
        int size = strlen(str);

        while(!st.empty())
            st.pop();

        for(int i = 0; i < size; ++i){
            if(str[i]=='(' || str[i]== '{' || str[i]=='['){
                st.push(str[i]);
            }
            else if(st.empty()){
                cout << "NO" << endl;
                break;
            }
            else if(st.top()==str[i]){
                st.pop();
                continue;
            }
            else{
                cout << "NO" << endl;
                break;
            }

            if(i == size-1 && st.empty())
                cout << "YES" << endl;
        }

    }
    return 0;
}
