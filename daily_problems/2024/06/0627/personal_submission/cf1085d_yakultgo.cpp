#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
    }
    if (n == 2) {
        cout << fixed << setprecision(18) << (double)s << endl;
        return;
    }
    sort(deg.begin(), deg.end(), greater<int>());
    ll mx = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += deg[i];
        mx = max(mx, sum - i * 2);
    }
    cout << fixed << setprecision(18) << (double)s * 2.0 / mx << endl;
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