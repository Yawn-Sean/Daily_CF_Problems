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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    int mi = *min_element(nums.begin(), nums.end());
    vector<int> cnt(3, 0), ncnt(3);

    for (auto &x: nums)
        cnt[x - mi] ++;
    
    int ans = n, chosen = 0;

    if (cnt[2]) {
        for (int i = - (cnt[1] / 2); i <= min(cnt[0], cnt[2]); i ++) {
            ncnt[0] = cnt[0] - i;
            ncnt[1] = cnt[1] + 2 * i;
            ncnt[2] = cnt[2] - i;

            int v = 0;
            for (int j = 0; j < 3; j ++)
                v += min(cnt[j], ncnt[j]);
            
            if (v < ans) ans = v, chosen = i;
        }
    }

    cnt[0] -= chosen;
    cnt[1] += 2 * chosen;
    cnt[2] -= chosen;

    cout << ans << '\n';
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < cnt[i]; j ++) {
            cout << mi + i << ' ';
        }
    }

    return 0;
}