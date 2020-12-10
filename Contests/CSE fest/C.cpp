#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("inp.txt", "r", stdin);
    int A, D;
    while(cin>>A>>D){
        if(A==0&&D==0)
            break;
        int com[A];
        int opp[D];
        for(int i = 0; i < A; ++i)
            cin>>com[i];
        for(int i = 0; i < D; ++i)
            cin>>opp[i];
        sort(com, com+A);
        sort(opp, opp+D);
        int x = 0;
        for(int i = 0; i < D; ++i){
            if(com[0]>=opp[i]){
                x = i;
                break;
            }
        }
        if(x>2) cout << "N" << endl;
        else cout << "Y" << endl;
    }
    fclose(inp);
    return 0;
}
