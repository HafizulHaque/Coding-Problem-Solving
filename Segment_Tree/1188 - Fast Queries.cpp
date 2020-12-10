#include<bits/stdc++.h>
using namespace std;

int n,m;
struct st
{
    int left,right,pos,ans,block;
}query[50010];

void setting(int l,int r,int b,int p)
{
    query[p].left=l; query[p].right=r; query[p].pos=p;
    query[p].block=b; query[p].ans=0; query[0].block=-1;
}

bool cmp(st a,st b)
{
    if(a.block==b.block)return a.right<b.right;
    else return a.block<b.block;
}

bool cmp1(st a, st b)
{
    return a.pos<b.pos;
}

int ara[100010];
int my[100010];

int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);

        int x,y,sq;
        sq=sqrt(n);

        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            setting(x,y,(x/sq),i);
        }
        sort(query+1,query+m+1,cmp);

        int lh,rh,coun,value;
        for(int i=1;i<=m;i++){
            st q=query[i];
            if(q.block!=query[i-1].block){
                lh=1; rh=1;coun=0;
                memset(my,0,sizeof(my));
            }

            while(rh<=q.right){
                value=ara[rh];
                my[value]++;
                if(my[value]==1)coun++;
                rh++;
            }
            while(lh>q.left){
                lh--;
                value=ara[lh];
                my[value]++;
                if(my[value]==1)coun++;
            }
            while(lh<q.left){
                value=ara[lh];
                my[value]--;
                if(my[value]==0)coun--;
                lh++;
            }
            query[i].ans=coun;
        }
        sort(query+1,query+m+1,cmp1);
        printf("Case %d:\n",++cs);
        for(int i=1;i<=m;i++)
            printf("%d\n",query[i].ans);
    }
}
