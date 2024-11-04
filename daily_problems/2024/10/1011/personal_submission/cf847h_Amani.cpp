#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve() {
    int n;
    cin >> n;
    vector<int> a(n+2, 0), b(n+2, 0), c(n+2, 0), d(n+2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    int ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= a[i-1]) {
            c[i] =  c[i-1] + a[i-1] - a[i] + 1;
            a[i] = a[i-1] + 1;
        } else {
            c[i] = c[i-1];
        }
    }
    for (int i = n; i >= 1; --i) {
        if (b[i] <= b[i+1]) {
            d[i] = d[i+1] + b[i+1] - b[i] + 1;
            b[i] = b[i+1] + 1;
        } else {
            d[i] = d[i+1];
        }
    }
    int res;
    for (int i = 0; i <= n; ++i) {
        res = a[i] != b[i+1] ? c[i] + d[i+1] : c[i] + d[i+1] + 1;
        ans = min(ans, res);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << endl;
    return 0;
}