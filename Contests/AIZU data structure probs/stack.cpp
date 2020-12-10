// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    char str[100];
    stack<long>st;
    while(scanf("%s", str) != EOF){
        if(strcmp(str, "+")==0){
            long b = st.top();
            st.pop();
            long a = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(strcmp(str, "-")==0){
            long b = st.top();
            st.pop();
            long a = st.top();
            st.pop();
            st.push(a-b);
        }
        else if(strcmp(str, "*")==0){
            long b = st.top();
            st.pop();
            long a = st.top();
            st.pop();
            st.push(a*b);
        }
        else{
            st.push(atoi(str));
        }
    }
    cout << st.top() << endl;
    //fclose(inp);
    return 0;
}
