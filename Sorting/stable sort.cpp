// accepted

#include <bits/stdc++.h>
using namespace std;

typedef struct Card{
    char type;
    int num;
    int sl;
    bool operator < (const Card &x) const{ return num<x.num; }
};

void sort_bubble(Card card[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= i+1; j--){
            if(card[j]<card[j-1]) swap(card[j], card[j-1]);
        }
    }
}

void sort_selection(Card card[], int n){
    for(int i = 0; i < n; ++i){
        int mini = i;
        for(int j = i; j < n; j++){
            if(card[j]<card[mini]) mini = j;
        }
        swap(card[i], card[mini]);
    }
}

void print_cards(Card card[], int n){
    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << card[i].type << card[i].num;
    }
    cout << endl;
}

void check_stability(Card card[], int n){
    for(int i = 0; i < n-1; ++i){
        if(card[i].num<card[i+1].num)
            continue;
        if(card[i].sl>card[i+1].sl){
            cout << "Not stable" << endl;
            return;
        }
    }
    cout << "Stable" << endl;
    return;
}

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    Card card1[n], card2[n];
    int val;
    char ch;
    for(int i = 0; i < n; ++i){
        cin>>ch>>val;
        card1[i].type = card2[i].type = ch;
        card1[i].num = card2[i].num = val;
        card1[i].sl = card2[i].sl = i;
    }
    sort_bubble(card1, n);
    sort_selection(card2, n);
    print_cards(card1, n);
    check_stability(card1, n);
    print_cards(card2, n);
    check_stability(card2, n);
    //fclose(inp);
    return 0;
}
