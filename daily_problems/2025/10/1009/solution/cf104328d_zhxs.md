- 问题等价于，是否存在一条长度大于 $\frac{n}{2}$ 的路径，使得路径中点的权值的最大公约数大于 $1$。
- 在树上，任意一条长度大于 $\frac{n}{2}$ 的路径，必然经过树的重心。
- 求出树的中心 $\text{mid}$，维护一个 `unordered_map<int, int>`，key 表示最大公约数 g，value 表示从 $\text{mid}$ 出发的路径中，最大公约数为 g 的路径的最大长度。如果可以把两条（相同 g 的）路径拼接起来，且长度大于 $\frac{n}{2}$，就有解。
- 时间复杂度 $O(N\log M)$，$\log$ 来自于 gcd 。

备注：因为点权范围是 `p_i \le 10^7`，所以可以直接用 `unordered_map`。数据范围如果更大建议手写哈希函数防卡。

参考代码（C++）
```cpp
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
```
