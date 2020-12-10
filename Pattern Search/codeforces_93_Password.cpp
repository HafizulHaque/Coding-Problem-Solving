#include<bits/stdc++.h>
using namespace std;

int z[3000010];
string txt,pat,ztxt;
vector<int>res,res1;

int zzz(int x)
{
    int l=0,r=0,k;
    for(int i=1;i<x;i++){
        if(i>r){
            l=r=i;
            while(r<x and ztxt[r]==ztxt[r-l])
                r++;
            z[i]=r-l;r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1)z[i]=z[k];
            else{
                l=i;
                while(r<x and ztxt[r]==ztxt[r-l])
                    r++;
                z[i]=r-l;r--;
            }
        }
    }
}
int main()
{
    cin>>txt;
    pat=txt;
    ztxt+=pat;ztxt+='#';ztxt+=txt;
    int a=txt.size(),b=ztxt.size();
    zzz(b);

    int count=0,mx1=0;
    for(int i=a+2;i<b;i++){
        if(i+z[i]==b) {
            res.push_back(z[i]);
            mx1=max(mx1,z[i]-1);
        }
        else if(i+z[i]<b)mx1=max(mx1,z[i]);
    }
    for(int i=0;i<res.size();i++)
        if(res[i]<=mx1)count=max(count,res[i]);

    if(count==0)
        cout<<"Just a legend"<<endl;
    else{
        for(int i=0;i<count;i++)
            cout<<txt[i];
    }

}

