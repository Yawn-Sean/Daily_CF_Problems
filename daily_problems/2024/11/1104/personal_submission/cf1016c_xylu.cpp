#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solveC() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> suf(n+1), sum(n+1);
    for (int i = n-1; i >= 0; i--) {
        int t = 2 * (n-1-i);
        suf[i] = sum[i+1] * t - suf[i+1] + (i % 2 ? a[i] : b[i]) * (t + 1LL);
        sum[i] = sum[i+1] + a[i] + b[i];
    }

    ll ans = suf[0], tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += 2LL * i * (a[i] + b[i]) + (i % 2 ? a[i] : b[i]);
        ans = max(ans, tmp + suf[i+1] + sum[i+1] * 2 * (i+1));
    }
    cout << ans << '\n';
}

int main() {
    solveC();
    return 0;
}
