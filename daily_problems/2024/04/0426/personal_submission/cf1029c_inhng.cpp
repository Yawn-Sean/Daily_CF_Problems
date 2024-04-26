#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0, mx_l = 0, mn_r = INF;
    cin >> n;
    vector<PII> a(n);
    for (PII &ai : a) {
        cin >> ai.ff >> ai.ss;
    }
    ranges::sort(a);
    for (int i = 0; i < n - 1; ++i) {
        mn_r = min(mn_r, a[i].ss);
    }
    ans = max(ans, mn_r - a[n - 2].ff);
    ranges::sort(a, [](PII x, PII y) {
        return x.ss < y.ss;
    });
    for (int i = 1; i < n; ++i) {
        mx_l = max(mx_l, a[i].ff);
    }
    ans = max(ans, a[1].ss - mx_l);
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
