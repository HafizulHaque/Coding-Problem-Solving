#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("D.txt", "r", stdin);
    int n;
    cin>>n;
    long oil_amount[n];
    long distance[n];
    memset(oil_amount, 0, sizeof(oil_amount));
    memset(distance, 0, sizeof(distance));
    long oil = 0, dis = 0;
    // input
    cin>>oil_amount[0]>>distance[0];
    for(int i = 1; i < n; ++i){
        cin>>oil>>dis;
        oil_amount[i] += oil_amount[i-1] + oil;
        distance[i] += distance[i-1] + dis;
    }

    //for(int i = 0; i < n; ++i){
     //   cout << "id = " << i << "  " << oil_amount[i] << "  " << distance[i] << endl;
   // }
    // main algorithm
    for(int i = 0; i < n; ++i){
        unsigned long long dis_sum = distance[i], petrol_sum = oil_amount[i];
        int current_index = i+1;
        while(current_index%n != i){

        }
    }
}
