#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    ll c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    ll ans = 0;
    for (ll i = 0; i * i <= c; i++) {
        if (i * wr <= c)
            ans = max(ans, i * hr + (c - i * wr) / wb * hb);
        if (i * wb <= c)
            ans = max(ans, i * hb + (c - i * wb) / wr * hr);
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