#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> suma(n + 1, 0), sumb(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        suma[i] = suma[i - 1] + a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        sumb[i] = sumb[i - 1] + b[i - 1];
    }
    // 最值只会是A和B中出现的元素
    // 枚举一下
    // b中的元素要小于等于cur
    // a中的元素要大于等于cur
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        ll cost = 1ll * i * cur - suma[i];
        int pos = lower_bound(b.begin(), b.end(), cur) - b.begin();
        cost += sumb[m] - sumb[pos] - 1ll * (m - pos) * cur;
        ans = min(ans, cost);
    }
    for (int i = 0; i < m; i++) {
        int cur = b[i];
        ll cost = sumb[m] - sumb[i] - 1ll * (m - i) * cur;
        int pos = lower_bound(a.begin(), a.end(), cur) - a.begin();
        cost += 1ll * pos * cur - suma[pos];
        ans = min(ans, cost);
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