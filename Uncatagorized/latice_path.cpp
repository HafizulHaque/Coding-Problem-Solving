#include<bits/stdc++.h>
using namespace std;
int x[] = {0, 1};
int y[] = {1, 0};
vector<int>vec;

void path(int a, int b){
   if(a>5||b>5){
        if(a==b)
           vec[0]++;
    return;
   }
   for(int i = 0; i < 2; ++i){
        path(a+x[i], b+y[i]);
   }
   return;
   printf("%d\n", vec[0]);
}

int main(){
    vec.push_back(3);
    path(0, 0);
    printf("%d\n", vec[0]);
}
