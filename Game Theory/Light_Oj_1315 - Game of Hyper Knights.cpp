#include<bits/stdc++.h>
using namespace std;
int ara[510][510];

int dx[]={-2,-3,-2,-1,-1,1};
int dy[]={1,-1,-1,-2,-3,-2};

int grundy(int x,int y)
{
    if(ara[x][y]!=-1)return ara[x][y];
    set<int>s;
    set<int>::iterator it;
    for(int i=0;i<6;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0 and xx<=500 and yy>=0 and yy<=500){
            s.insert(grundy(xx,yy));
        }
    }

    int k=0;
    for(it=s.begin();it!=s.end();it++){
        if(*it!=k)break;
        k++;
    }
    return ara[x][y]=k;
}

int main()
{
    memset(ara,-1,sizeof(ara));
    for(int i=0;i<=500;i++)
        for(int j=0;j<500;j++)grundy(i,j);

    int t,n,x,y,k;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        cin>>n;
        k=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            k^=ara[x][y];
        }
        if(k>0)printf("Case %d: Alice\n",cc);
        else printf("Case %d: Bob\n",cc);
    }

}
