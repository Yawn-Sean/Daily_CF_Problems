#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 * 32 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;
#define int long long

int fast_pow(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int as = fast_pow(10, a - 1), ae = fast_pow(10, a) - 1;
    int bs = fast_pow(10, b - 1), be = fast_pow(10, b) - 1;
    int cs = fast_pow(10, c - 1), ce = fast_pow(10, c) - 1;
    for (int x = as; x <= ae; ++x) {
        int mn = max(bs, cs - x);
        int mx = min(be, ce - x);
        if (mn > mx) continue;
        int len = mx - mn + 1;
        if (k > len) {
            k -= len;
        } else {
            int y = mn + k - 1;
            cout << x << " + " << y << " = " << x + y << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
