
// accepted

#include <bits/stdc++.h>
using namespace std;
typedef struct Item{
    int price;
    int piece;
};
#define mss map<string,Item>

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    string name, device;
    int price;
    mss users;
    for(int i = 0; i < 6; ++i){
        cin>>name>>device>>price;
        Item item;
        item.price = price;
        item.piece = 1;
        pair<mss::iterator, bool> itr = users.insert(make_pair(device,item));
        if(itr.second==false){
            mss::iterator itemItr = itr.first;
            (itemItr->second).piece++;
            (itemItr->second).price = min((itemItr->second).price, price);
        }
    }
    int max_user=0, min_price=100000000;
    for(auto itr = users.begin(); itr != users.end(); ++itr){
        if((itr->second).piece>max_user) max_user = (itr->second).piece;
    }
    for(auto itr = users.begin(); itr != users.end(); ++itr){
        if((itr->second).piece==max_user&&(itr->second).price<min_price){
            min_price = (itr->second).price;
            device = itr->first;
        }
    }
    cout << device << endl;
    //fclose(inp);
    return 0;
}
