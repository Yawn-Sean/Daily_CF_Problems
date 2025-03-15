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

int get(int x, int y) {
    if (x < 0)
        return 0;
    return x / y + 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int num = n / k;

    vector<int> a(num + 1, 0), b(num + 1, 0);
    rep(i, 1, num) cin >> a[i];
    rep(i, 1, num) cin >> b[i];

    int e = 1;
    rep(i, 1, k) e *= 10;

    i64 ans = 1;
    rep(i, 1, num) {
        int e0 = e / 10;
        i64 x = get(e - 1, a[i]), y = get((b[i] + 1) * e0 - 1, a[i]) - get(b[i] * e0 - 1, a[i]);
        ans = ans * (x - y) % MOD;
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
