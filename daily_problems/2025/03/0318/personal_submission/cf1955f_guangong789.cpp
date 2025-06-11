/*
1: 0001
2: 0010
3: 0011
4: 0100
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = (a % 2 && b % 2 && c % 2) ? 1 : 0;
    ans += (a/2 + b/2 + c/2 + d/2);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}