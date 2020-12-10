#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int tree[3*mx];
char s[mx];

void init(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
        tree[node]=0;
        return;
    }
    left=node*2;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[right]+tree[left];
}

void update(int node,int b,int e,int i,int j,int x)
{
    int left,right,mid;
    if(b>j or e<i)return;
    if(b>=i and e<=j){
        tree[node]+=x;
        return;
    }
    left=node*2;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
}

int query(int node,int b,int e,int i,int c)
{
    int left,right,mid,p1,p2;
    if(b>i or e<i)return 0;
    if(b==e){
        return tree[node]+c;
    }
    left=node*2;
    right=left+1;
    mid=(b+e)/2;
    p1=query(left,b,mid,i,c+tree[node]);
    p2=query(right,mid+1,e,i,c+tree[node]);
    return p1+p2;
}

int main()
{
    int t,cas=0,q,a,b,l;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s ",s);
        l=strlen(s);l--;
        init(1,0,l);
        scanf("%d",&q);
        printf("Case %d:\n",++cas);
        while(q--){
            getchar();
            scanf("%c",&c);
            if(c=='I'){
                scanf("%d %d",&a,&b);
                a--,b--;
                update(1,0,l,a,b,1);
            }
            else{
                scanf("%d",&a);a--;
                int v=query(1,0,l,a,0);
                if(v%2==0)printf("%c\n",s[a]);
                else{
                    if(s[a]=='0')printf("1\n");
                    else printf("0\n");
                }
            }
        }
    }
}
