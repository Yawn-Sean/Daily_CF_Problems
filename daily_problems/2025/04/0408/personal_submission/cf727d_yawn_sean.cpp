#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums(6);
    for (auto &x: nums) cin >> x;

    vector<vector<int>> tmp0(6), tmp1(5);
    vector<string> sz = {"S", "M", "L", "XL", "XXL", "XXXL"};
    map<string, int> mp;
    for (int i = 0; i < 6; i ++) mp[sz[i]] = i;

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        string s, cur;
        bool flg = false;

        cin >> s;
        for (auto &c: s) {
            if (c != ',') cur += c;
            else {
                flg = true;
                break;
            }
        }

        if (flg) tmp1[mp[cur]].emplace_back(i);
        else tmp0[mp[cur]].emplace_back(i);
    }

    vector<string> ans(n);
    for (int i = 0; i < 6; i ++) {
        while (tmp0[i].size()) {
            int idx = tmp0[i].back();
            tmp0[i].pop_back();
            if (!nums[i]) return cout << "NO", 0;
            nums[i] --, ans[idx] = sz[i];
        }
    }

    for (int i = 0; i < 5; i ++) {
        while (tmp1[i].size()) {
            int idx = tmp1[i].back();
            tmp1[i].pop_back();
            if (nums[i])
                nums[i] --, ans[idx] = sz[i];
            else if (nums[i + 1])
                nums[i + 1] --, ans[idx] = sz[i + 1];
            else return cout << "NO", 0;
        }
    }

    cout << "YES\n";
    for (auto &x: ans)
        cout << x << '\n';

    return 0;
}