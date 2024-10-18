#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), d(m + 1, vector<int>(m + 1));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) cin >> a[i][j];
        for (int i = 0; i < n - 1; ++i) a[i][j] -= a[n-1][j];
    }
    vector<int> ans(m);
    ranges::iota(ans, 1);
    int sz = 0;
    auto clear = [](vector<int> &v) { ranges::fill(v, -inf); };
    for (int k = 0; k < n - 1; ++k) {
        ranges::for_each(d, clear);
        d[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            d[i][0] = 0;
            for (int j = 1; j <= i; ++j) {
                d[i][j] = max(d[i-1][j], d[i-1][j-1] + a[k][i-1]);
            }
        }
        int j = m;
        for (; j >= 0 && d[m][j] < 0; --j);
        if (sz < j) {
            sz = j;
            ans.clear();
            int i = m;
            while (i) {
                if (j && d[i][j] == d[i-1][j-1] + a[k][i-1]) --j;
                else ans.push_back(i);
                --i;
            }
        }
    }
    println("{}", m - sz);
    for (auto v: ans) print("{} ", v);
    println();
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
