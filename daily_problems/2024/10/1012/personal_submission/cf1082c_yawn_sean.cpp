#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> groups(m + 1);

    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        groups[x].emplace_back(y);
    }

    vector<int> ans(n + 1, 0);
    for (int i = 0; i <= m; i ++) {
        sort(groups[i].rbegin(), groups[i].rend());
        int cur = 0;
        for (int j = 0; j < groups[i].size(); j ++) {
            cur += groups[i][j];
            if (cur > 0) ans[j + 1] += cur;
        }
    }

    cout << *max_element(ans.begin(), ans.end());

    return 0;
}