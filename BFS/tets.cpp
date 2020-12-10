#include<bits/stdc++.h>
using namespace std;

#define max 100
vector<int>edge[100];
int ara[max][2];
int n,e;
int bfs(int n)
{
    for(int i=1;i<=n;i++){
        cout<<ara[i][0]<<' '<<ara[i][1]<<endl;
        for(int j=0;j<edge[i].size();j++)
            cout<<edge[i][j]<<' ';
        cout<<endl;
    }

}
int main()
{
    while(cin>>n>>e){
            int n1,n2;
            memset(ara,0,sizeof(ara));
        for(int i=0;i<e;i++){
            cin>>n1>>n2;
            edge[n1].push_back(n2);
            ara[n1][1]++;
            ara[n2][0]++;
        }
        bfs(n);
    }
}
