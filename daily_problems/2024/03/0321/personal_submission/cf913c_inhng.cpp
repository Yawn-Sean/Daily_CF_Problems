#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, l, ans = INF, cnt = 0;
    cin >> n >> l;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (i) { // 更新每个位置的最低价格
            c[i] = min(c[i], (c[i - 1] << 1));
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        ans = min(ans, cnt + c[i] * ((l - 1) / (1 << i) + 1));
        int v = l / (1 << i);
        l -= (v << i);
        cnt += v * c[i];
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
