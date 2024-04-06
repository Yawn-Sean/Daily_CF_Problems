#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, i;
    cin >> n >> m;
    vector<int> a(n + 1);
    double res = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        double cur = 0;
        cur = 1.0 * (a[u] + a[v]) / w;
        if (cur > res) res = cur;
    }
    cout << fixed << setprecision(10) << res << '\n'; 
    return 0;
}
