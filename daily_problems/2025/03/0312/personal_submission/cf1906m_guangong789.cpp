#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, s = 0, mx = 0, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        mx = max(mx, tmp);
        s += tmp;
    }
    if (2 * (s - mx) <= mx) {
        cout << (s - mx);
    } else {
        cout << (s / 3);
    }
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