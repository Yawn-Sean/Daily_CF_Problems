#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);

        for (int i = 0; i < n; i ++)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        
        vector<long long> acc(n + 1);
        for (int i = 0; i < n; i ++)
            acc[i+1] = acc[i] + a[i];
        
        set<int> vis;

        function<void(int, int)> f = [&](int l, int r) {
            if (acc[r+1] - acc[l] <= 1e9)
                vis.emplace(acc[r+1] - acc[l]);
            if (a[l] != a[r]) {
                int nl = upper_bound(a.begin() + l, a.begin() + r, (a[l] + a[r]) / 2) - a.begin();
                f(l, nl - 1);
                f(nl, r);
            }
        };

        f(0, n - 1);

        for (int i = 0; i < q; i ++) {
            int s;
            cin >> s;
            cout << (vis.find(s) != vis.end() ? "Yes\n" : "No\n");
        }
    }

    return 0;
}