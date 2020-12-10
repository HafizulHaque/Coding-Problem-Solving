#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int n,m;
bool my[mx];

struct st
{
    int left,right,block,pos,ans;
}query[mx];

void setting(int l,int r,int b,int i,int a){
    query[i].left=l; query[i].right=r; query[i].block=b;
    query[i].pos=i; query[i].ans=a; query[0].block=-1;
}

bool cmp(st a,st b)
{
    if(a.block==b.block)return a.right<b.right;
    else return a.block<b.block;
}

bool cmp1(st a,st b)
{
    return a.pos<b.pos;
}

int ara[mx];
int findv[mx];

int check(int i,int p)
{
    int c=0;
    int value=ara[i];
    if(value>100000)c=0;
    else{
        if(p==1)findv[value]++;
        if(p==2)findv[value]--;

        if(findv[value]==value){
            c=1;
            my[value]=1;
        }
        else{
            if(my[value]==1){
                my[value]=0;
                c=-1;
            }
        }
    }
    return c;
}

int main()
{
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        int l,r,sq;
        sq=sqrt(n);

        for(int i=1;i<=m;i++){
            scanf("%d %d",&l,&r);
            setting(l,r,(l/sq),i,0);
        }
        sort(query+1,query+m+1,cmp);

        int lh,rh,coun;
        for(int i=1;i<=m;i++){
            st q=query[i];
            if(q.block!=query[i-1].block){
                lh=1;
                rh=1;
                coun=0;
                memset(findv,0,sizeof(findv));
                memset(my,0,sizeof(my));
            }

            while(rh<=q.right){
                coun+=check(rh,1);
                rh++;
            }
            while(lh>q.left){
                lh--;
                coun+=check(lh,1);
            }
            while(lh<q.left){
                coun+=check(lh,2);
                lh++;
            }
            query[i].ans=coun;
        }

        sort(query+1,query+m+1,cmp1);
        for(int i=1;i<=m;i++)printf("%d\n",query[i].ans);
    }
}

