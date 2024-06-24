#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> f(n + 5, 0); // f[i]: 变成i的方案数
    vector<int> sum(n + 5, 0); // sum[i]: 变成i,i + 1, …… ,n的方案数之和
    f[n] = 1, sum[n] = 1;
    for (int i = n - 1; i > 0; --i) {
        f[i] = sum[i + 1];
        for (int j = 2; i * j <= n; ++j)
            f[i] = (m + f[i] + sum[i * j] - sum[min(n + 1, i * j + j)]) % m;
        sum[i] = (sum[i + 1] + f[i]) % m;
    }
    cout << f[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
