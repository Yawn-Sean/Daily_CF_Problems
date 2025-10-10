#include <iostream>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> edge(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> pre(n);
    auto dfs = [&edge, &pre](auto &&self, int u, int fa) -> pair<int, int>
    {
        pair<int, int> ans{0, u};
        pre[u] = fa;
        for (auto v : edge[u])
        {
            if (v == fa)
                continue;
            ans = max(ans, self(self, v, u));
        }
        ans.first++;
        return ans;
    };

    int s = dfs(dfs, 0, -1).second;
    auto [d, mid] = dfs(dfs, s, -1);
    for (int i = 0; i < d / 2; i++)
        mid = pre[mid];

    unordered_map<int, int> max_prefix;
    for (auto v : edge[mid])
    {
        unordered_map<int, int> cur_mp;

        auto dfs = [&edge, &cur_mp, &a](auto &&self, int u, int fa, int g, int d) -> void
        {
            cur_mp[g] = max(cur_mp[g], d);
            for (auto v : edge[u])
            {
                if (v == fa)
                    continue;
                self(self, v, u, gcd(g, a[u]), d + 1);
            }
        };

        dfs(dfs, v, mid, gcd(a[mid], a[v]), 1);

        for (auto [g, d] : cur_mp)
        {
            if (g > 1 && max_prefix[g] + d + 1 > n / 2)
            {
                cout << "YES" << endl;
                return 0;
            }
            max_prefix[g] = max(max_prefix[g], d);
        }
    }
    cout << "NO" << endl;
    return 0;
}