#include <bits/stdc++.h>
using namespace std;
int main(){
    //FILE *inp_file = freopen("inp.txt", "r", stdin);
    long long n;
    int count = 0;
    set<long long> s;
    set<long long>::iterator itr;
    long long sum = 0;
    cin>>n;
    while(n != 1){
        s.insert(n);
        while(n != 0){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        count++;
        n = sum;
        sum = 0;
        itr = find(s.begin(), s.end(), n);
        if(itr != s.end()){
            cout << -1 << endl;
            //fclose(inp_file);
            return 0;
        }
    }
    cout << count << endl;
    //fclose(inp_file);
    return 0;
}
