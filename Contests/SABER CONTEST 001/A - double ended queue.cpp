// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *file = freopen("A.txt", "r", stdin);
    int test;
    cin>>test;
    for(int x = 1; x <= test; ++x){
        cout << "Case " << x << ":" << endl;
        int n, m;
        deque<int> deq;
        deq.clear();
        char cmd[100];
        int cmd_num;
        cin>>n>>m;
        for(int i = 0; i < m; ++i){
            cin>>cmd;
            if(strcmp(cmd, "pushLeft")==0 || strcmp(cmd, "pushRight")==0){
                cin>>cmd_num;
                if(deq.size()>=n)
                    cout << "The queue is full" << endl;
                else{
                    if(strcmp(cmd, "pushLeft")==0){
                        deq.push_front(cmd_num);
                        cout << "Pushed in left: " << cmd_num << endl;
                    }
                    else if(strcmp(cmd, "pushRight")==0){
                        deq.push_back(cmd_num);
                        cout << "Pushed in right: " << cmd_num << endl;
                    }
                }
            }
            else{
                if(deq.size()==0){
                    cout << "The queue is empty" << endl;
                }
                else{
                    if(strcmp(cmd, "popLeft")==0){
                        cout << "Popped from left: " << deq.front() << endl;
                        deq.pop_front();
                    }
                    else if(strcmp(cmd, "popRight")==0){
                        cout << "Popped from right: " << deq.back() << endl;
                        deq.pop_back();
                    }
                }
            }
        }

    }
    //fclose(file);
    return 0;
}
