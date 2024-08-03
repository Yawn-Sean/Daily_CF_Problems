#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    int mi = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        int x;
        cin >> x;
        if (x <= 0) {
            x = -x;
            cnt++;
        }
        ans += x;
        mi = min(mi, x);
    }
    if (cnt % 2 == 1 && n % 2 == 0) {
        ans -= 2 * mi;
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