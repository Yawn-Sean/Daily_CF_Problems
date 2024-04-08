#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<ll> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    vector<ll> ans(n, 0);
    for (int i = 1; i <= n - 1; i++) {
        int pre = 1;
        ll base = i;
        ll j = i + 1;
        for (int step = 1;; step++) {
            ans[i] += (sum[j] - sum[pre]) * step;
            pre = j;
            if (pre >= n)
                break;
            base *= i;
            j += base;
            if (j >= n)
                j = n;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        if (k >= n - 1)
            k = n - 1;
        cout << ans[k] << " ";
    }
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