// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sevenCount=INT_MAX, fourCount=INT_MAX;

void update(ll s, ll f){
    if(s+f<sevenCount+fourCount||(s+f==sevenCount+fourCount&&s<sevenCount)){
        sevenCount = s;
        fourCount = f;
    }
}

void formNumber(){
    if(sevenCount==INT_MAX&&fourCount==INT_MAX) printf("-1\n");
    else{
        for(ll i = 0; i < fourCount; ++i) printf("4");
        for(ll i = 0; i < sevenCount; ++i) printf("7");
        printf("\n");
    }
}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    ll n, s, f;
    scanf("%lld", &n);
    s = n/7;
    for(ll i = 0; i <= s; ++i){
        if(!((n-7*i)%4)) update(i, (n-7*i)/4);
    }
    formNumber();
    //fclose(inp);
    return 0;
}
