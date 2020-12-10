#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define mx 160110

int tree[3*mx];
map<int,lli>my;

void update(int node,int b,int e,int i)
{
    int left,right,mid;
    if(i>e or i<b)return;
    if(b==i and e==i){
        tree[node]=1;
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i);
    update(right,mid+1,e,i);
    tree[node]=tree[left]+tree[right];
   // cout<<node<<' '<<tree[node]<<endl;
    return;
}

int query(int node,int b,int e,int i)
{
    int left,right,mid;
    if(b==e){
        tree[node]--;
        return b;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    int p;
  //  cout<<i<<' '<<left<<' '<<tree[left]<<' '<<right<<' '<<tree[right]<<endl;
    if(tree[left]!=0 and (i<=tree[left] or tree[right]==0)){
        p=query(left,b,mid,i);
    }
    else{
        i=i-tree[left];
        p=query(right,mid+1,e,i);
    }
    tree[node]=tree[right]+tree[left];
    //cout<<node<<' '<<tree[node]<<endl;
    return p;
}

int main()
{
    int t,cs=0,n,q;
    lli a;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&q);
        int x=0,count=0;

        memset(tree,0,sizeof tree);
        my.clear();

        for(int i=0;i<n;i++){
            scanf("%lld",&a);
            my[++x]=a;
            update(1,1,mx-2,x);
            count++;
        }

        char c;
        printf("Case %d:\n",++cs);
        while(q--){
                getchar();
            scanf("%c",&c);
            if(c=='a'){
                count++;
                scanf("%lld",&a);
                my[++x]=a;
                update(1,1,mx-2,x);
            }
            else{
               scanf("%lld",&a);
               if(a>count)printf("none\n");
               else{
                    count--;
                    int y=query(1,1,mx-2,a);
                    printf("%lld\n",my[y]);
               }
            }
        }
    }
}


