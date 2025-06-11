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

    int n;
    cin >> n;
    int k = 32 - __builtin_clz(n);

    auto query = [&] (vector<int> ar) -> vector<int> {
        cout << ar.size() << '\n';
        for (auto &x: ar) cout << x << ' ';
        cout << '\n';
        cout.flush();

        vector<int> ans(n);
        for (auto &x: ans) cin >> x;
        return ans;
    };

    vector<vector<int>> saved0(n, vector<int>(k)), saved1(n, vector<int>(k));
    for (int bit = 0; bit < k; bit ++) {
        vector<int> tmp, res;

        for (int i = 1; i <= n; i ++)
            if ((i >> bit & 1) == 0) tmp.emplace_back(i);
        res = query(tmp);
        for (int j = 0; j < n; j ++)
            saved0[j][bit] = res[j];
        
        tmp.clear();

        for (int i = 1; i <= n; i ++)
            if (i >> bit & 1) tmp.emplace_back(i);
        res = query(tmp);
        for (int j = 0; j < n; j ++)
            saved1[j][bit] = res[j];
    }

    cout << -1 << '\n';
    for (int i = 0; i < n; i ++) {
        int cur = 1e9;
        for (int bit = 0; bit < k; bit ++) {
            if ((i + 1) >> bit & 1) cur = min(cur, saved0[i][bit]);
            else cur = min(cur, saved1[i][bit]);
        }
        cout << cur << ' ';
    }

    return 0;
}