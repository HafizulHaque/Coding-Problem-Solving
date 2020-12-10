// a program that finds BFS Edges ( Forward Edge, BackEdges, Tree Edge, Cross Edge )

#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

#define forward forward1

const int maxn = 2e5;

vector<int> g[maxn];
int tree, back, forward, cross;

int in[maxn], h[maxn];
int timer;

set<pair<int, int>> finished;
vector<int> st;

void dfs(int u)
{
    in[u] = timer++;
    st.push_back(u);

    for (int v: g[u])
    {
        h[v] = h[u] + 1;
        dfs(v);
    }

    st.pop_back();

    for (int v: st)
    {
        if (back <= 0)
            break;
        g[u].push_back(v);
        --back;
    }
    for (auto p: finished)
    {
        if (cross <= 0)
            break;
        if (p.first >= in[u])
            break;
        int v = p.second;
        g[u].push_back(v);
        --cross;
    }
    for (auto it = finished.rbegin(); it != finished.rend(); ++it)
    {
        if (forward <= 0)
            break;
        if (it->first <= in[u])
            break;
        int v = it->second;
        if (h[v] == h[u] + 1)
            continue;
        g[u].push_back(v);
        --forward;
    }

    finished.emplace(in[u], u);
}

int main()
{
    cin >> tree >> back >> forward >> cross;
    int n = tree + 1;
    int minSumH = max(tree + forward, back);
    int maxSumH = n * (n - 1) / 2 - cross;
    if (maxSumH < minSumH)
    {
        cout << -1 << '\n';
        return 0;
    }
    int sumH = tree;
    forab (i, 1, n)
    {
        if (sumH + i - 1 <= minSumH)
        {
            g[i - 1].push_back(i);
            sumH += i - 1;
        }
        else
        {
            g[minSumH - sumH].push_back(i);
            sumH += minSumH - sumH;
        }
    }
    if (sumH < minSumH)
    {
        cout << -1 << '\n';
        return 0;
    }
    dfs(0);
    assert(back == 0);
    assert(forward == 0);
    assert(cross == 0);
    assert(sumH == accumulate(h, h + n, 0));
    cout << n << '\n';
    forn (i, n)
    {
        cout << sz(g[i]);
        for (int v: g[i])
            cout << ' ' << v + 1;
        cout << '\n';
    }
    return 0;
}

