#include<bits/stdc++.h>
using namespace std;
long long ara[60][60];

int main()
{
    int t,n,m,cc;
    cin>>t;

    for(int cc=1;cc<=t;cc++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ara[i][j];
                ara[i][j]+=ara[i][j-1];
            }
        }

        long long k=0;
        for(int i=1;i<=n;i++) k^=(ara[i][m]);

        if(k>0)printf("Case %d: Alice\n",cc);
        else printf("Case %d: Bob\n",cc);
    }
}


