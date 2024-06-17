#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> rs;
    vector<vector<int>> segs_l(2e5 + 1), segs_r(2e5 + 1);

    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        rs.push_back(r);
        segs_l[l].push_back(i);
        segs_r[r].push_back(i);
    }

    set<pair<int, int>> tmp;
    vector<int> ans;

    for (int i = 0; i < 2e5 + 1; i ++) {
        for (auto &x: segs_l[i]) tmp.emplace(make_pair(rs[x], x));
        while (tmp.size() > k) {
            auto &[r, i] = *tmp.rbegin();
            ans.push_back(i);
            tmp.erase(*tmp.rbegin());
        }
        for (auto &x: segs_r[i])
            if (tmp.find(make_pair(i, x)) != tmp.end())
                tmp.erase(make_pair(i, x));
    }
    cout << ans.size() << '\n';
    for (auto &x: ans)
        cout << x + 1 << ' ';

    return 0;
}