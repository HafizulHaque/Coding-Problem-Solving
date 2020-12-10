#include <bits/stdc++.h>
using namespace std;

typedef struct Item{
    int weight;
    int value;
    double unit_value;
    int weight_taken;
    bool operator > (const Item &p)  const { return unit_value>p.unit_value; }
};
int main(){
    FILE *inp = freopen("inp.txt", "r", stdin);
    int n;
    cin>>n;
    Item item[n];
    for(int i = 0; i < n; ++i){
        cin>> item[i].weight >> item[i].value;
        item[i].unit_value = item[i].value/(double)item[i].weight;
        item[i].weight_taken = 0;
    }
    sort(item, item+n, greater<Item>());

    int W = 50;
    int w = 0;
    int i = 0;
    while(w<=W && i<n){
        item[i].weight_taken = min(item[i].weight, W-w);
        w += item[i].weight_taken;
        i++;
    }
    for(int i = 0; i < 3; ++i){
        cout << item[i].weight << "  " << item[i].value << "  " << item[i].unit_value << "  " << item[i].weight_taken << endl;
    }
    double total_benifit = 0;
    for(int i = 0; i < n; ++i){
        total_benifit += item[i].weight_taken*item[i].unit_value;
    }
    cout << "Total Benifit : " << total_benifit << endl;
    fclose(inp);
    return 0;
}
