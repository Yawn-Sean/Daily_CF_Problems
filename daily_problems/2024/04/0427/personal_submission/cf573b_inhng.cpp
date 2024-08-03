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
    int n, ans = 0;
    cin >> n;
    vector<int> h(n + 2), l(n + 2), r(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        l[i] = min(h[i], l[i - 1] + 1);
    }
    for (int i = n; i; --i) {
        r[i] = min(h[i], r[i + 1] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, min(l[i], r[i]));
    }
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
