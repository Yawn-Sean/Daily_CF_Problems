#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[] = { 0, 0, 1, 2, 9 };

void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 1, c = n;
    for (int r = 1; r <= k; ++r) ans += c * d[r], (c *= n - r) /= r + 1;
    cout << ans << endl;
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
