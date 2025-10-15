#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
void sub(int& a, int b) {
    a = ((a - b) % MOD + MOD) % MOD;
}
void solve() {
    int n, kr, kg, kb;
    cin >> n >> kr >> kg >> kb;
    vector<int> dpr(n + 1), dpg(n + 1), dpb(n + 1);
    dpr[1] = dpg[1] = dpb[1] = 1;
    for (int i = 2; i <= n; i++) {
        int total = (dpr[i - 1] + dpg[i - 1] + dpb[i - 1]) % MOD;
        dpr[i] = total;
        if (i > kr + 1) {
            sub(dpr[i], dpg[i - kr - 1]);
            sub(dpr[i], dpb[i - kr - 1]);
        } else if (i == kr + 1) {
            sub(dpr[i], 1);
        }
        dpg[i] = total;
        if (i > kg + 1) {
            sub(dpg[i], dpr[i - kg - 1]);
            sub(dpg[i], dpb[i - kg - 1]);
        } else if (i == kg + 1) {
            sub(dpg[i], 1);
        }
        dpb[i] = total;
        if (i > kb + 1) {
            sub(dpb[i], dpr[i - kb - 1]);
            sub(dpb[i], dpg[i - kb - 1]);
        } else if (i == kb + 1) {
            sub(dpb[i], 1);
        }
    }
    int ans = (dpr[n] + dpg[n] + dpb[n]) % MOD;
    cout << ans << endl;
}

signed main() {
    IOS;
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}