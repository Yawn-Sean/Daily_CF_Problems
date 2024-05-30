#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mx = *max_element(a.begin(), a.end());
    vector<Z> f(mx + 1);
    FenwickTree ft(mx);
    for (int i = 0; i < n; i++) {
        Z t = (ft.query(a[i]) + 1) * a[i] - f[a[i]];
        f[a[i]] += t;
        ft.add(a[i], t);
    }
    Z ans = 0;
    for (int i = 1; i <= mx; i++) {
        ans += f[i];
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