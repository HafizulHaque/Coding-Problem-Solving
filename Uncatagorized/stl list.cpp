#include <bits/stdc++.h>
using namespace std;

int main(){             // not sorted, double connected linked list.
    list<int> li;
    li.push_back(0);
    li.push_front(4);
    li.insert(li.end(),-1);
    li.insert(li.begin(),9);

    for(auto itr = li.begin(); itr != li.end(); itr++)
        printf("%d  ", *itr);
    printf("\n");
    return 0;
}
