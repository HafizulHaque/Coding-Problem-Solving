#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *file = freopen("C.txt", "r", stdin);
    int test_case;
    cin>>test_case;
    while(test_case--){
        int m, n, num, _cnt = 0;
        long long x, suma = 0, sumb = 0;
        stack<int> a, b;
        //a.clear();
        //b.clear();
        cin>>m>>n>>x;
        for(int i = 0; i < m; ++i){
            cin>>num;
            suma += num;
            a.push(suma);
        }
        for(int i = 0; i < n; ++i){
            cin>>num;
            sumb += num;
            b.push(sumb);
        }

        while((a.top()+b.top())>x){
            int a_top = a.top();
            int b_top = b.top();
            a.pop();
            b.pop();
            if(a_top>b_top)
                b.push(b_top);
            else if(b_top>a_top)
                a.push(a_top);
            else if(a_top==b_top){
                if(a.top()>b.top())
                    b.push(b_top);
                else if(a.top()<b.top())
                    a.push(a_top);
            }
        }
        cout << a.size()+b.size() << endl;
    }
    //fclose(file);
    return 0;
}
