#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("inn.txt", "r", stdin);
    string exp;
    stack<char>st, post;
    cin>>exp;
    // add a ) in the exp - by default will be given
    st.push('(');
    for(int i = 0; i < exp.length(); i++){
        if(exp[i]=='(') st.push('(');
        else if(exp[i]=='0|'||exp[i]=='1'||exp[i]=='2'||exp[i]=='4'||exp[i]=='5'||exp[i]=='6'||exp[i]=='7'||exp[i]=='8'||exp[i]=='9'){
            post.push(exp[i])
        }
    }
}
