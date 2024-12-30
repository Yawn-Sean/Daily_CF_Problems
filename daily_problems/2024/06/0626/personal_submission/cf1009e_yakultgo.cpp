#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Z ans = 0;
    Z mi[n + 1];
    mi[0] = 1;
    for (int i = 1; i <= n; i++) {
        mi[i] = mi[i - 1] * Z(2);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += (mi[n - i] + (n - i) * (n - i - 1 >= 0 ? mi[n - i - 1] : 0)) * a[i];
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