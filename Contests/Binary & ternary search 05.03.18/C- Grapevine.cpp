#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int M, N;
    while(cin>>M>>N && M && N){
        vector<vi> H;
        for(int i = 0; i < M; ++i){
            vi row;
            for(int j = 0; j < N; ++j){
                int h;
                cin>>h;
                row.push_back(h);
            }
            H.push_back(row);
            row.clear();
        }
        int Q;
        cin>>Q;
        while(Q--){
            int lo, hi;
            cin>>lo>>hi;
            int s = 0;
            for(int row = 0; row < M; ++row){
                vi& row_data = H[row];
                vi::iterator lo_it = lower_bound(row_data.begin(), row_data.end(), lo);
                int col = distance(row_data.begin(), lo_it);

                for(int new_s = s+1; (row+new_s-1)<M && (col+new_s-1)<N ; ++new_s){
                    int dig_row = row+new_s-1;
                    int dig_col = col+new_s-1;

                    if(H[dig_row][dig_col]<=hi){
                        s = new_s;
                    }
                    else{
                        break;
                    }
                }
            }
            cout << s << endl;
        }
        cout << '-' << endl;
    }
    //fclose(inp);
    return 0;
}
