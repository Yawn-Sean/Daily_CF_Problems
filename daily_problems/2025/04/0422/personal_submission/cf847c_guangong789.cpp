#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 * 32 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    if ((n * n - n) / 2 < k) {
        cout << "Impossible";
        return;
    }
    int c = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (k >= c) {
            k -= c;
            cout << '(';
            c++;
        } else {
            cout << ')';
            c--;
        }
    }
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