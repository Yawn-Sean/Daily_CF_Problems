#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN int(2e5 + 10)
#define MOD int(1e9 + 7)
#define rep(i, start, end) for (int i = start; i <= end; ++i)
#define erp(i, end, start) for (int i = end; i >= start; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[1] != 0) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> f(n + 1, vector<int>(3, INT_MIN));
    f[0][0] = 0;
    rep(i, 1, n) {
        int r0 = a[i] % 3;
        rep(r, 0, 2) {
            int r1 = (r0 + r) % 3;
            f[i][r1] = max(f[i - 1][r1], f[i - 1][r] + 1);
        }
    }
    string ans = "";
    int e = 0;
    erp(i, n, 1) {
        int r = a[i] % 3, s = (e - r + 3) % 3;
        if (f[i - 1][s] + 1 == f[i][e]) {
            ans += to_string(a[i]);
            e = s;
        }
    }
    if (ans[0] == '0') {
        cout << "0" << endl;
        return;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
