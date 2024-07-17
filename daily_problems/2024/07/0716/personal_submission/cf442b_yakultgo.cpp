#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ranges::sort(a, greater());
    double ans = a.front();
    double x = ans;
    double mul = 1 - x;
    for (int i = 1; i < n; i++) {
        ans = max(ans, x + a[i] * (mul - x));
        x = x * (1.0 - a[i]) + a[i] * mul;
        mul *= 1.0 - a[i];
    }
    cout << fixed << setprecision(15) << ans << endl;
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