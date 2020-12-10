#include<bits/stdc++.h>
using namespace std;

#define mx 100010

int tree[mx],ara[mx],n;

int query(int idx)
{
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int idx,int value)
{
    while(idx<=n){
        cout<<idx<<endl;
        tree[idx]+=value;
        idx+=(idx&-idx);
    }
}
int main()
{
    int t,cs=0,q,z,x,y,v=0;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&q);
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++){
            scanf("%d",&z);
            ara[i]=z;
            update(i,z);
        }

        printf("Case %d:\n",++cs);
        while(q--){
            scanf("%d",&z);
            if(z==1){
                scanf("%d",&x);
                x++;
                v=ara[x];
                ara[x]=0;
                update(x,-v);
            }
            else if(z==2){
                scanf("%d %d",&x,&y);
                x++;
                ara[x]+=y;
                update(x,y);
                continue;
            }
            else{
                scanf("%d %d",&x,&y);
                y++;
                v=query(y)-query(x);
            }
            printf("%d\n",v);
        }
    }
}
