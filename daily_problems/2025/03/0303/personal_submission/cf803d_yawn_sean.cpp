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
// I came, I divide, I conquer!

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    cin.ignore();

    string s;
    getline(cin, s);

    vector<int> nums;
    int cnt = 0;

    for (auto &c: s) {
        cnt ++;
        if (c == ' ' || c == '-') {
            nums.emplace_back(cnt);
            cnt = 0;
        }
    }

    nums.emplace_back(cnt);

    int l = *max_element(nums.begin(), nums.end()), r = 1000000;

    while (l <= r) {
        int m = (l + r) / 2;

        int cur = 0, cnt = 1;
        for (auto &v: nums) {
            cur += v;
            if (cur > m) {
                cur = v;
                cnt ++;
            }
        }

        if (cnt > k) l = m + 1;
        else r = m - 1;
    }

    cout << l;

    return 0;
}