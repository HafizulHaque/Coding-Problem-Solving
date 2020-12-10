
#include<bits/stdc++.h>
using namespace std;

#define forbid -1
#define siz 30
int dx[]={0,0,1,0,0,-1};
int dy[]={0,1,0,0,-1,0};
int dz[]={1,0,0,-1,0,0};

int level[siz][siz][siz];
int vis[siz][siz][siz];
string start,finish;


struct value
{
    int x,y,z;
    value(){};

    value(int a,int b,int c){x=a;y=b;z=c;}
};

int bfs(string src)
{
    queue<value>q;

    int x=(src[0]-'a'); int y=(src[1]-'a'); int z=(src[2]-'a');
    int d0=finish[0]-'a'; int d1=finish[1]-'a'; int d2=finish[2]-'a';
    vis[x][y][z]=1;
    level[x][y][z]=0;
    q.push(value(x,y,z));

    int max=-1;

    while(!q.empty()){
        value p=q.front();q.pop();
        if(p.x==d0 and p.y==d1 and p.z==d2){
            max=level[d0][d1][d2];
            break;
        }

        for(int m=0;m<6;m++){
            int a=(p.x+dx[m])%26;
            int b=(p.y+dy[m])%26;
            int c=(p.z+dz[m])%26;

            if(a<0)a+=26;
            if(b<0)b+=26;
            if(c<0)c+=26;

            if(vis[a][b][c]==0){
                vis[a][b][c]=1;
                level[a][b][c]=level[p.x][p.y][p.z]+1;
                q.push(value(a,b,c));
            }
        }
    }
    //cout<<max<<endl;

    return max;
}

int main()
{
    int t,cas=0;
    cin>>t;

    while(t--){
        string s1,s2,s3;
        cin>>start>>finish;
        int n;
        cin>>n;
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));

        for(int r=0;r<n;r++){
            cin>>s1>>s2>>s3;

            int l1=s1.length(),l2=s2.length(),l3=s3.length();
            for(int i=0;i<l1;i++){
                    for(int j=0;j<l2;j++){
                        for(int k=0;k<l3;k++){
                            int x=(s1[i]-'a');
                            int y=(s2[j]-'a');
                            int z=(s3[k]-'a');
                           //cout<<x<<' '<<y<<' '<<z<<endl;
                            vis[x][y][z]=forbid;
                        }
                    }
            }

        }
        int x=(start[0]-'a'); int y=(start[1]-'a'); int z=(start[2]-'a');
        //cout<<vis[x][y][z]<<endl;
        if(vis[x][y][z]==forbid){
            printf("Case %d: -1\n",++cas);
        }
        else{
            int flag=0;
            flag=bfs(start);
            //cout<<flag<<endl;
            if(flag==-1)printf("Case %d: -1\n",++cas);
            else printf("Case %d: %d\n",++cas,flag);
        }
    }
}


