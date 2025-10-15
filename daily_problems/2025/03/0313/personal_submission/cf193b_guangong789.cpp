#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, u, r;
    cin >> n >> u >> r;
    vector<int> a(n+1), b(n+1), k(n+1), p(n+1);
    for (size_t i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (size_t i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (size_t i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    for (size_t i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    int ans = -1e18;
    function<void(vector<int>&, int, bool)> dfs;
    dfs = [&](vector<int> &cur, int steps, bool last_op) -> void {
        if ((u - steps) % 2 == 0) {  // 还有偶数步可操作，偶数次异或不改变答案的值
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                res += cur[i] * k[i];
            }
            ans = max(ans, res);
        }
        if (steps == u) {
            return;
        }
        steps++;
        vector<int> tmp(n+1);
        for (int i = 1; i <= n; ++i) {
            tmp[i] = cur[p[i]] + r;  // 进行操作2
        }
        dfs(tmp, steps, false);
        if (!last_op) {
            for (int i = 1; i <= n; ++i) {
                tmp[i] = cur[i] ^ b[i];  // 枚举在哪一步进行最后一次有效的异或
            }
            dfs(tmp, steps, true);
        }
    };
    dfs(a, 0, false);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 暴力搜索dfs