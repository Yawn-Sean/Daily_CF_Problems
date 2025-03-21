#include <bits/stdc++.h>
using namespace std;

void solve() {
    float r, h;
    int ans = 0;
    cin >> r >> h;
    while (h >= r) {
        h -= r;
        ans += 2;
    }
    if (h >= (sqrt(3)*r) / 2) {
        ans += 3;
    } else if (h >= r / 2) {
        ans += 2;
    } else {
        ans += 1;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}