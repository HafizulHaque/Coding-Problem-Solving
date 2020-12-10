#include<bits/stdc++.h>
using namespace std;
int ara[100][100];
int d[100][100];
int main()
{
    int x,y,n;
    cin>>n;
    int path[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cin>>ara[i][j];
            if(ara[i][j]==0)
                path[i][j]=0;
            else
                path[i][j]=ara[i][j];
        }

    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                path[i][j]=path[i][j] or (path[i][k] and path[k][j]);
            }
        }
        cout<<"Path matrix: "<<k<<endl;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
           cout<<path[i][j]<<' ';
        }
        cout<<endl;
    }

    }


}
