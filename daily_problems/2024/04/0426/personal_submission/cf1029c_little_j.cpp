#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

const int mod = 1e9 + 7;


int m, n, d, k;

using pll = pair<int,int>;


void solve() {
    cin >> n;
    int l[n], r[n];
    int bl[n + 1], br[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    bl[n - 1] = l[n - 1];
    br[n - 1] = r[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        bl[i] = max(bl[i + 1], l[i]);
        br[i] = min(br[i + 1], r[i]);
    }
    int res = bl[1] <= br[1] ? br[1] - bl[1]: 0;
    int ll = l[0], rr = r[0];
    for (int i = 1; i < n; ++i) {
        if (i == n - 1) {
            res = max(res, max(0, rr - ll));
        } else {
            int ml = max(ll, bl[i + 1]), mr = min(rr, br[i + 1]);
            res = max(res, max(0, mr - ml));
            ll = max(ll, l[i]);
            rr = min(rr, r[i]);
        }
    }
    cout << res << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    int t;
//    cin >> t;
//    while (t--) solve();
    return 0;
}
