#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    ll ans = 0;
    ll p = 1;
    for (int i = 0; i < n; i++) {
        if (p > k) {
            ans += k;
            continue;
        }
        p <<= 1;
        if (a[i] == 'b') p--;
        if (b[i] == 'a') p--;
        ans += min(p, 1ll * k);
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