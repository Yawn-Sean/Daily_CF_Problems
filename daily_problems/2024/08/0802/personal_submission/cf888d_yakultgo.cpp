#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll comb(int n, int m) {
    ll res = 1;
    for (int i = n, j = 1; j <= m; j++, i--) {
        res = res * i / j;
    }
    return res;
}
void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k >= 4) ans += comb(n, 4) * 9;
    if (k >= 3) ans += comb(n, 3) * 2;
    if (k >= 2) ans += comb(n, 2);
    if (k >= 1) ans += 1;
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