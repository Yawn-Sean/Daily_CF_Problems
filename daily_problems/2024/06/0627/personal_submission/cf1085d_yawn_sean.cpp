#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> degs(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        degs[--u] ++, degs[--v] ++;
    }

    int cnt = 0;
    for (auto &x: degs) cnt += x == 1;

    cout << setprecision(12) << 2.0 * s / cnt;

    return 0;
}