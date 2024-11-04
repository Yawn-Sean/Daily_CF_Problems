#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> xs(n), ys(n);

        for (int i = 0; i < n; i ++) {
            cin >> xs[i] >> ys[i];
            if (xs[i] > ys[i]) swap(xs[i], ys[i]);
        }

        vector<int> order(n), ans(n, -2);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j){return xs[i] < xs[j] ? 1 : (xs[i] == xs[j] && ys[i] > ys[j]);});

        int cur = 1e9 + 1, idx = -1;
        for (auto &x: order) {
            if (ys[x] <= cur) {
                cur = ys[x];
                idx = x;
            }
            else {
                ans[x] = idx;
            }
        }

        for (auto &x: ans) cout << x + 1 << ' ';
        cout << '\n';
    }

    return 0;
}