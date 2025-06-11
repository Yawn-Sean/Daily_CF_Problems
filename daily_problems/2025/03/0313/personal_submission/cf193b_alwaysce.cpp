#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, u, r;
    cin >> n >> u >> r;
    vector<int> a(n), b(n), k(n), p(n);
    for (auto&x: a) { cin >> x; }
    for (auto&x: b) { cin >> x; }
    for (auto&x: k) { cin >> x; }
    for (auto&x: p) { cin >> x; x--; }

    i64 ans = -1e18;
    // 连续的两次操作1=没有操作 但是会影响步数总和
    // (当前step, 上次操作是否是第一种操作, 当前数组的状态)
    function<void(vector<int>&, int, bool)> dfs = [&](vector<int>& cur, int steps, bool is_final) {
        if (((u - steps) & 1) == 0) {
            // 剪枝: 距离最终态有偶数步的状态
            // 后面全操作1 正好等于没操作
            i64 res = 0;
            for (int i = 0; i < n; i++) {
                res += 1ll * cur[i] * k[i];
            }
            ans = max(ans, res);
        }

        if (steps == u) {
            return;
        }
        ++steps;

        vector<int> ncur(n);
        for (int i = 0; i < n; i++) {
            ncur[i] = cur[p[i]] + r;
        }
        dfs(ncur, steps, false);

        if (!is_final) {
            for (int i = 0; i < n; i++) {
                ncur[i] = cur[i] ^ b[i];
            }
            dfs(ncur, steps, true);
        }
    };
    dfs(a, 0, false);
    cout << ans;
    return 0;
}
