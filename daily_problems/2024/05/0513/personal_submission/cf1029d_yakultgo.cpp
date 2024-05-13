#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int l[N];
int a[N];
vector<int> g[11];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mi[11];
    mi[0] = 1;
    for (int i = 1; i <= 10; i++) {
        mi[i] = 1ll * mi[i - 1] * 10 % k;
    }
    for (int i = 1; i <= n; i++) {
        int y = a[i];
        while (y) {
            l[i]++;
            y /= 10;
        }
        for (int j = 1; j <= 10; j++) {
            int x = 1ll * a[i] * mi[j] % k;
            g[j].push_back(x);
        }
    }
    for (int i = 1; i <= 10; i++) sort(g[i].begin(), g[i].end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = (k - a[i] % k) % k;
        auto left = lower_bound(g[l[i]].begin(), g[l[i]].end(), tmp);
        auto right = upper_bound(g[l[i]].begin(), g[l[i]].end(), tmp);
        ans += right - left;
        if ((1ll * a[i] * mi[l[i]] + a[i]) % k == 0) ans--;
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