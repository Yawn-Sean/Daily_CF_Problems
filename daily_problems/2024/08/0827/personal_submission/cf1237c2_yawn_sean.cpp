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

    vector<int> xs(n), ys(n), zs(n);
    for (int i = 0; i < n; i ++) 
        cin >> xs[i] >> ys[i] >> zs[i];
    
    vector<pair<int, int>> ans;

    auto solve1 = [&] (vector<int> tmp) -> vector<int> {
        sort(tmp.begin(), tmp.end(), [&](int i, int j) {return zs[i] < zs[j];});
        while (tmp.size() > 1) {
            int x = tmp.back();
            tmp.pop_back();
            int y = tmp.back();
            tmp.pop_back();
            ans.emplace_back(x, y);
        }
        return tmp;
    };

    auto solve2 = [&] (vector<int> lst) -> vector<int> {
        sort(lst.begin(), lst.end(), [&](int i, int j) {return ys[i] < ys[j];});
        vector<int> resid, tmp;
        for (auto &i: lst) {
            if (tmp.size() != 0 && ys[i] != ys[tmp[0]]) {
                for (auto &x: solve1(tmp))
                    resid.emplace_back(x);
                tmp.clear();
            }
            tmp.emplace_back(i);
        }
        for (auto &x: solve1(tmp))
            resid.emplace_back(x);
        while (resid.size() > 1) {
            int x = resid.back();
            resid.pop_back();
            int y = resid.back();
            resid.pop_back();
            ans.emplace_back(x, y);
        }
        return resid;
    };

    auto solve3 = [&] (vector<int> lst) {
        sort(lst.begin(), lst.end(), [&](int i, int j) {return xs[i] < xs[j];});
        vector<int> resid, tmp;
        for (auto &i: lst) {
            if (tmp.size() != 0 && xs[i] != xs[tmp[0]]) {
                for (auto &x: solve2(tmp))
                    resid.emplace_back(x);
                tmp.clear();
            }
            tmp.emplace_back(i);
        }
        for (auto &x: solve2(tmp))
            resid.emplace_back(x);
        while (resid.size() > 1) {
            int x = resid.back();
            resid.pop_back();
            int y = resid.back();
            resid.pop_back();
            ans.emplace_back(x, y);
        }
    };

    vector<int> to_solve(n);
    iota(to_solve.begin(), to_solve.end(), 0);
    solve3(to_solve);

    for (auto &[x, y]: ans)
        cout << x + 1 << ' ' << y + 1 << '\n';


    return 0;
}