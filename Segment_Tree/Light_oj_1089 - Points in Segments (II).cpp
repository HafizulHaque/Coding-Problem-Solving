#include<bits/stdc++.h>
using namespace std;

#define mx 200010
#define pii pair<int,int>

vector<int>vec,que;
vector<pii>segment;
map<int,int>my;

struct st
{
    int sum,prop;
}tree[3*mx];

void update(int node,int b,int e,int i,int j,int x)
{
    int left,right,mid;
    if(b>j or e<i)return;
    if(b>=i and e<=j){
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry)
{
    int left,right,mid,p1,p2;
    if(b>j or e<i)return 0;
    if(b>=i and e<=j){
        return tree[node].sum+(e-b+1)*carry;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j,carry+tree[node].prop);
    p2=query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}
void clr()
{
    vec.clear();que.clear();
    segment.clear();my.clear();
}

int main()
{
    int t,cs=0;
    scanf("%d",&t);

    while(t--){
        int n,x,y,q;
        scanf("%d %d",&n,&q);

        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            vec.push_back(x);
            vec.push_back(y);
            segment.push_back(pii(x,y));
        }

        for(int i=0;i<q;i++){
            scanf("%d",&x);
            vec.push_back(x);
            que.push_back(x);
        }

        sort(vec.begin(),vec.end());
        x=1;
        for(int i=0;i<vec.size();i++){
            if(my[vec[i]]==0)my[vec[i]]=x++;
        }

        memset(tree,0,sizeof tree);
        for(int i=0;i<segment.size();i++){
            int u=segment[i].first;
            int v=segment[i].second;
            u=my[u];v=my[v];
            update(1,1,x,u,v,1);
        }

        printf("Case %d:\n",++cs);
        for(int i=0;i<que.size();i++){
            int u=que[i];
            u=my[u];
            y=query(1,1,x,u,u,0);
            printf("%d\n",y);
        }
        clr();
    }
}
