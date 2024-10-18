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

    vector<vector<int>> ars;
    vector<int> ma_val;

    while (n --) {
        int v;
        cin >> v;
        v = -v;
        int p = lower_bound(ma_val.begin(), ma_val.end(), v) - ma_val.begin();
        if (p == ma_val.size()) {
            ars.push_back({v});
            ma_val.emplace_back(v);
        }
        else {
            ars[p].emplace_back(v);
            ma_val[p] = v;
        }
    }

    for (auto &ar: ars) {
        for (auto &x: ar) cout << -x << ' ';
        cout << '\n';
    }

    return 0;
}