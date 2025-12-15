#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

/*
遇到 1 的时候是最后一次删除
遇到被删除的点，不算操作
我们考虑 1 位于不同位置时的期望操作次数，加起来就是整个的了
或者，考虑操作 cnt 次的方案有多少种？

先考虑一下 1 位于不同位置时的期望操作次数怎么算吧，设为 dp[i]
考虑 dp[i - 1] 和 dp[i] 之间的关系
我们关心的是 dp[i] 中的 i - 1 位置选的点是啥
- 如果是没删的点，操作次数就 + 1
- 如果是之前删过的子树中的点，操作次数不变 

羊的提示：还有一个思路，考虑 u 点被删除的贡献期望
u 点有贡献，当且仅当其祖先之前没被删除
u 有 d[u] - 1 个祖先，他们都不能出现在序列中 u 的前面
*/

vector<LL> fact(N), invfact(N);
const int mod = 998244353;

LL qpow(LL a, LL b, LL mod) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    vector<int> d(n + 1, 0);
    
    auto dfs = [&] (auto &&self, int u, int fa) -> void {
        d[u] = d[fa] + 1;
        // cout << u << " " << d[u] << "\n";
        for (auto v : e[u]) {
            if (v != fa) {
                self(self, v, u);
            }
        }
    };
    
    dfs(dfs, 1, 0);
    
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + qpow(d[i], mod - 2, mod)) % mod;
    }
    cout << res << "\n";
}
