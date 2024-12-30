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

    string s;
    cin >> s;

    vector<vector<int>> ans;
    vector<int> tmp0, tmp1;

    for (int i = 0; i < s.size(); i ++) {
        if (s[i] - '0') {
            if (tmp0.size()) {
                tmp1.emplace_back(tmp0.back());
                tmp0.pop_back();
                ans[tmp1.back()].emplace_back(i + 1);
            }
            else {
                cout << -1;
                return 0;
            }
        }
        else {
            if (tmp1.size()) {
                tmp0.emplace_back(tmp1.back());
                tmp1.pop_back();
                ans[tmp0.back()].emplace_back(i + 1);
            }
            else {
                tmp0.emplace_back(ans.size());
                ans.push_back({i + 1});
            }
        }
    }

    if (tmp1.size()) cout << -1;
    else {
        cout << ans.size() << '\n';
        for (auto &x: ans) {
            cout << x.size() << ' ';
            for (auto &v: x)
                cout << v << ' ';
            cout << '\n';
        }
    }

    return 0;
}