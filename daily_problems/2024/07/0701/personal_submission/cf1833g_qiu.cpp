#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;
vector<PII> e[N];
bool ok;
vector<int> dp(N);
vector<int> ans;

void dfs(int u, int fa, int op)
{
    int leaf = 0;
    int other = 0;
    vector<int> temp;
    for (auto [v, id] : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u, id);
        if (e[v].size() == 1)
        {
            leaf++;
        }
        else if (dp[v] >= 1)
        {
            other++;
            temp.push_back(dp[v]);
        }
    }
    if (leaf + other > 2)
        ok = true;
    if (leaf == 0 && other == 1)
    {
        if (temp[0] == 1)
        {
            dp[u] = 0;
            if (op != 0)
                ans.push_back(op);
        }
        else if (temp[0] == 2)
        {
            dp[u] = 1;
        }
        else
            dp[u] = 1;
    }
    else if (leaf == 0 && other == 2)
    {
        if (temp[0] == temp[1] && temp[1] == 2)
        {
            dp[u] = 0;
            if (op != 0)
                ans.push_back(op);
        }
        else
            ok = true;
    }
    else if (leaf == 1 && other == 1)
    {
        if (temp[0] == 2)
        {
            dp[u] = 0;
            if (op != 0)
                ans.push_back(op);
        }
        else
            ok = true;
    }
    else if (leaf == 1 && other == 0)
    {
        dp[u] = 1;
    }
    else if (leaf == 0 && other == 0)
        dp[u] = 2;
    else if (leaf == 2 && other == 0)
    {
        dp[u] = 0;
        if (op != 0)
            ans.push_back(op);
    }
}
void solve()
{
    int n;
    cin >> n;
    ok = false;
    ans.clear();
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        dp[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i + 1});
        e[v].push_back({u, i + 1});
    }
    dfs(1, 0, 0);
    // for()
    if (ok || n % 3 != 0)
        cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (auto v : ans)
        {
            cout << v << ' ';
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
