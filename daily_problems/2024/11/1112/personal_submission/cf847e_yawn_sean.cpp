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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<int> asterisks, packmen;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '*') asterisks.emplace_back(i);
        else if (s[i] == 'P') packmen.emplace_back(i);
    }

    int l = 0, r = 2 * n, k = asterisks.size();

    while (l <= r) {
        int m = (l + r) / 2, pt = 0;

        for (auto &p: packmen) {
            if (abs(asterisks[pt] - p) > m) continue;
            int left = max(0, p - asterisks[pt]);
            int right = p + max((m - left) / 2, m - left * 2);
            while (pt < k && asterisks[pt] <= right)
                pt ++;
            if (pt == k) break;
        }

        if (pt == k) r = m - 1;
        else l = m + 1;
    }

    cout << l;

    return 0;
}