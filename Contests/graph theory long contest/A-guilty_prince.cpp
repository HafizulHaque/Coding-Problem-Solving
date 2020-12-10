#include <bits/stdc++.h>
using namespace std;

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};

bool is_safe(int x, int y, int X, int Y){
    return x>=0&&x<X&&y>=0&&y<Y;
}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        int h, w;
        cin>>w>>h;
        char pos[h][w];
        char taken[h][w];
        pair<int, int> init_pos;

        for(int j = 0; j < h; ++j){
            for(int k = 0; k < w; ++k){
                taken[j][k] = 0;
                cin>>pos[j][k];
                if(pos[j][k]=='@') init_pos = make_pair(j, k);
                if(pos[j][k]=='#') taken[j][k] = 1;
            }
        }

        int count = 1;
        queue<pair<int, int> > q;

        q.push(init_pos);
        taken[q.front().first][q.front().second] = 1;

        while(!q.empty()){
            int a, b;
            a = q.front().first;
            b = q.front().second;
            q.pop();
            for(int j = 0; j < 4; ++j){
                if(is_safe(a+x[j], b+y[j], h, w)&&taken[a+x[j]][b+y[j]]==0){
                    q.push(make_pair(a+x[j], b+y[j]));
                    taken[a+x[j]][b+y[j]] = 1;
                    count++;
                }
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }
    //fclose(inp);
    return 0;
}
