#include<bits/stdc++.h>
using namespace std;

vector<int>v,v1;
int vis[1010],level[1010];
bool ara[110];
int x,y;

int save_prime()
{
    v.push_back(2);
    ara[2]=1;
    ara[1]=1;
    for(int i=3;i<=1000;i+=2){
            int flag=0;
        for(int j=2;j<=(i/2)+1;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
               // cout<<i<<endl;
                ara[i]=1;
            v.push_back(i);
        }
    }
}

int prime_factor(int src)
{
    int i=0;
    int c=v[i];
    //cout<<src<<' '<<x<<endl;
    while(1){
        if(src<=1)break;
        if(src%c==0){
            v1.push_back(c);
            while(1){
                if(src%c!=0)break;
                else src/=c;
            }
        }
        else{
            i++;
            if(i==v.size())break;
            c=v[i];
        }
    }
}

int bfs(int src)
{
  queue<int>q;
  q.push(src);
  vis[src]=1;
  level[src]=0;
  int min=-1;
  while(!q.empty()){
        v1.clear();
        int u=q.front();q.pop();
        //cout<<u<<endl;
        prime_factor(u);
        for(int i=0;i<v1.size();i++){
            //cout<<v1[i]<<' ';
            int a=u+v1[i];
            if(vis[a]==1)continue;
            if(a>y)continue;
            if(a==y){
                level[a]=level[u]+1;
                min=level[a];
                vis[a]=1;
                while(!q.empty())q.pop();
                break;
            }
            vis[a]=1;
            level[a]=level[u]+1;
            q.push(a);
        }
        //cout<<endl;
    }
   // cout<<min<<endl;
    return min;
}
int main()
{
   int t,cas=0;
   cin>>t;
   memset(ara,0,sizeof(ara));
   save_prime();
   while(t--){
        cin>>x>>y;

        memset(level,0,sizeof(level));
        memset(vis,0,sizeof(vis));
        v1.clear();
        //cout<<x<<' '<<y<<' '<<ara[x]<<endl;
        if(x==y)printf("Case %d: 0\n",++cas);
        else if(ara[x]==1){
            printf("Case %d: -1\n",++cas);
        }
        else{
            printf("Case %d: %d\n",++cas,bfs(x));
        }
   }
}
