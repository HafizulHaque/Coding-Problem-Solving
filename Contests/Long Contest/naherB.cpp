#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

int a[maxn], l[maxn], r[maxn];
int sum[maxn], n;

void update(int x)
{
    for (int i = x; i <= n; i += Lowbit(i))
        sum[i] += 1;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= Lowbit(i))
        res += sum[i];
    return res;
}

int main()
{
    //FILE *inp = freopen("in.txt","r",stdin);

    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(sum, 0, sizeof(sum));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            l[a[i]] = min(a[i], i);
            r[a[i]] = i + a[i] - 1 - query(a[i]);
            update(a[i]);
        }
        printf("Case #%d:", ncase);
        for (int i = 1; i <= n; i++)
            printf(" %d", r[i] - l[i]);
        printf("\n");
    }
    return 0;
}
