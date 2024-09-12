#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n), sz(1 << n), sum(1 << n);
    vector<vector<int>> ans(101, vector<int>(1 << n));
    for (int i = 0; i < n; ++i) cin >> w[n-i-1];
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int p = 0;
        for (int j = 0; j < n; ++j) p = p * 2 + s[j] - '0';
        ++sz[p];
    }
    for (int i = 1; i < (1 << n); ++i) sum[i] = sum[i ^ (i & -i)] + w[__builtin_ctz(i & -i)];
    for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) if (sum[j] <= 100) ans[sum[j]][((1<<n)-1)&~(i^j)] += sz[i];
    for (int i = 1; i <= 100; ++i) for (int j = 0; j < (1 << n); ++j) ans[i][j] += ans[i-1][j];
    while (q--) {
        string t; int k;
        cin >> t >> k;
        int p = 0;
        for (int j = 0; j < n; ++j) p = p * 2 + t[j] - '0';
        println("{}", ans[k][p]);
    }
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
