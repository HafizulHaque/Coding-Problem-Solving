#include<bits/stdc++.h>
using namespace std;
int ara[100][100];
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
                path[i][j]=100;
            else
                path[i][j]=ara[i][j];
        }

    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<path[i][j]<<' '<<path[i][k] +path[k][j]<<endl;
             path[i][j]=min(path[i][j] , (path[i][k] +path[k][j]));
            }
        }
        cout<<"Path matrix: "<<k<<endl;
       for(int g=0;g<n;g++){
        for(int h=0;h<n;h++)
        {
           cout<<path[g][h]<<' ';
        }
        cout<<endl;
    }

    }

}

