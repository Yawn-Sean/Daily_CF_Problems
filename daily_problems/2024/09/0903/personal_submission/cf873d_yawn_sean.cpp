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

    int n, k;
    cin >> n >> k;

    if ((k & 1) == 0)
        return cout << -1, 0;
    
    vector<int> ans(n), help(n);
    iota(ans.begin(), ans.end(), 1);

    auto op = [&] (auto &self, int l, int r) {
        if (k == 0 || l + 1 == r) return;
        int m = (l + r) / 2;
        k --;
        for (int i = l; i < r; i ++)
            help[i] = ans[i];
        for (int i = l; i < m; i ++)
            ans[i] = help[i+r-m];
        for (int i = m; i < r; i ++)
            ans[i] = help[i-m+l];
        self(self, l, m);
        self(self, m, r);
    };

    k /= 2;
    op(op, 0, n);

    if (k) cout << -1;
    else for (auto &x: ans) cout << x << ' ';

    return 0;
}