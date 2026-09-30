#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 2000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, m;
    cin >> n >> m;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }

    vector<i64> dp(2001);
    for (int i = 1; i <= n; i++) {
        for (int j = f[i][0]; j <= 2000; j++) {
            dp[j] = max(dp[j], dp[j - f[i][0]] + f[i][1]);
        }
    }

    auto dfs = [&](this auto&& dfs, int l, int r) -> vector<i64> {
        if (r <= 2000) {
            return vector<i64>(dp.begin() + l, dp.begin() + r + 1);
        }

        int cl = max<int>(0, l / 2 - 500), cr = r / 2 + 500;
        auto v = dfs(cl, cr);

        vector<i64> ans(r - l + 1);
        for (int i = cl; i <= cr; i++) {
            for (int j = i; j <= cr; j++) {
                if (i + j >= l && i + j <= r) {
                    ans[i + j - l] = max(ans[i + j - l], v[i - cl] + v[j - cl]);
                }
            }
        }
        return ans;
    };

    cout << dfs(m, m)[0];
    return 0;
}