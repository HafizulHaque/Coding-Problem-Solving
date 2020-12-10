// accepted

#include <bits/stdc++.h>
using namespace std;
#define N 10010
vector<int> prime_list;

void seive(){
    int prime[N];
    memset(prime, 1, sizeof(prime));
    prime_list.clear();
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 0; i*i <= N; i++){
        if(prime[i]){
            for(int j = 2*i; j < N; j += i) prime[j] = 0;
        }
    }
    for(int i = 0; i < N; ++i)
        if(prime[i]) prime_list.push_back(i);
}

int check_prime(int num){
    if(num == 2) return 1;
    if(!num&1) return 0;

    int state = 1;
    int size = prime_list.size();
    for(int i = 0; i < size && prime_list[i]*prime_list[i]<=num; ++i){
        if(!(num%prime_list[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, num;
    int prime_cnt = 0;
    seive();
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>num;
        if(check_prime(num)){
            prime_cnt++;
        }
    }
    cout << prime_cnt << endl;
    //fclose(inp);
    return 0;
}
