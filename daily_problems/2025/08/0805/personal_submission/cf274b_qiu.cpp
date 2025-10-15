#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> e;
vector<int> a, big, small;

void dfs(int u, int fa)
{
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        big[u] = max(big[u], big[v]);
        small[u] = max(small[u], small[v]);
    }

    int num = a[u] + big[u] - small[u];
    if (num > 0)
        small[u] += num;
    else
        big[u] -= num;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    e.assign(n + 1, vector<int>());
    a.assign(n + 1, 0);
    big.assign(n + 1, 0);
    small.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dfs(1, 0);
    cout << big[1] + small[1] << "\n";

    return 0;
}
