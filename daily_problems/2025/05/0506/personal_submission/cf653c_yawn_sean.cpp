#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    auto check = [&] (int idx) -> bool {
        if (idx & 1) return nums[idx] > nums[idx + 1];
        return nums[idx] < nums[idx + 1];
    };

    vector<bool> cur(n - 1);
    int res = 0;

    for (int i = 0; i < n - 1; i ++)
        cur[i] = check(i), res += cur[i];

    vector<bool> vis(n, 0);
    int ans = 0;

    for (int i = 0; i < n - 1; i ++) {
        if (!cur[i]) {
            for (int u = i; u <= i + 1; u ++) {
                for (int v = 0; v < n; v ++) {
                    if (u == i && v == i + 1) continue;
                    swap(nums[u], nums[v]);

                    int nres = res;
                    for (int nu = u - 1; nu <= u; nu ++) {
                        if (nu >= 0 && nu < n - 1 && !vis[nu]) {
                            vis[nu] = 1;
                            nres -= cur[nu];
                            nres += check(nu);
                        }
                    }

                    for (int nv = v - 1; nv <= v; nv ++) {
                        if (nv >= 0 && nv < n - 1 && !vis[nv]) {
                            vis[nv] = 1;
                            nres -= cur[nv];
                            nres += check(nv);
                        }
                    }

                    if (nres == n - 1) ans ++;

                    for (int nu = u - 1; nu <= u; nu ++)
                        if (nu >= 0 && nu < n - 1)
                            vis[nu] = 0;

                    for (int nv = v - 1; nv <= v; nv ++)
                        if (nv >= 0 && nv < n - 1)
                            vis[nv] = 0;
                    
                    swap(nums[u], nums[v]);
                }
            }
            break;
        }
    }

    cout << ans;

    return 0;
}