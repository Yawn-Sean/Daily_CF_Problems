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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> cnt(m + 2);
    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        cnt[l] += 1;
        cnt[r + 1] -= 1;
    }

    for (int i = 1; i <= m + 1; i ++)
        cnt[i] += cnt[i - 1];
    
    vector<int> tmp, v1(m + 2, 0), v2(m + 2, 0);
    for (int i = 1; i <= m; i ++) {
        int p = upper_bound(tmp.begin(), tmp.end(), cnt[i]) - tmp.begin();
        if (p == tmp.size()) tmp.emplace_back(cnt[i]);
        else tmp[p] = cnt[i];
        v1[i] = tmp.size();
    }

    tmp.clear();
    
    for (int i = m; i >= 1; i --) {
        int p = upper_bound(tmp.begin(), tmp.end(), cnt[i]) - tmp.begin();
        if (p == tmp.size()) tmp.emplace_back(cnt[i]);
        else tmp[p] = cnt[i];
        v2[i] = tmp.size();
    }

    int ans = 0;
    for (int i = 0; i <= m; i ++)
        ans = max(ans, v1[i] + v2[i + 1]);

    cout << ans;

    return 0;
}