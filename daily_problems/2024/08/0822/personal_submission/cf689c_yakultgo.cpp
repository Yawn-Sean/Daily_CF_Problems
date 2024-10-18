#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll l = 8, r = 1e18;
    ll ans = -1;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 2; i * i * i <= mid; i++) {
            cnt += mid / (i * i * i);
        }
        if (cnt == n) {
            ans = mid;
        }
        if (cnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}