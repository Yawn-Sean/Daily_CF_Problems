//  D. Absolute Cinema
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> f(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    vector<i64> d(n + 5);
    for (int i = 1; i < n; i++) {
        d[i] = f[i] - f[i + 1];
    }
    d[n] = f[n] - f[1];
    i64 sum = (f[1] + f[n]) / (n - 1);
    vector<i64> a(n + 5);
    a[1] = (sum - d[1]) / 2;
    for (int i = 2; i < n; i++) {
        a[i] = (d[i - 1] - d[i]) / 2;
    }
    a[n] = (sum + d[n - 1]) / 2;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
