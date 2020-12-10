#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAX 10000
vector<int>edges[MAX];
vector<int>in[MAX];
vector<int>out[MAX];
void print();

int main()
{
  int N,E,x,y;
  cin>>N>>E;

  for(int i=1;i<=E;i++){
        cin>>x>>y;
        out[x].push_back(y);
        in[y].push_back(x);
  }
  print();
  return 0;
}
void print()
{
   for(int i=0;i<=4;i++){
    cout<<"Indegree of Node "<<i<<':'<<endl;
    int siz=in[i].size();
    if(siz==0)
        cout<<0<<endl;
    else{
        for(int j=0;j<siz;j++)
            cout<<in[i][j]<<' ';
            cout<<endl;
    }

    cout<<"Outdegree of Node "<<i<<':'<<endl;
    siz=out[i].size();
    if(siz==0)
        cout<<0<<endl;
    else{
        for(int j=0;j<siz;j++)
            cout<<out[i][j]<<' ';
            cout<<endl;
    }
}
}
