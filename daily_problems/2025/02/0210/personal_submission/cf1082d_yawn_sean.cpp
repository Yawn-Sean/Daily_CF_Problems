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

    vector<int> nums(n), chain, nodes;

    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        if (nums[i] == 1) nodes.emplace_back(i);
        else chain.emplace_back(i);
    }

    int l = chain.size();
    if (l == 0) cout << "NO";
    else {
        vector<pair<int, int>> edges;

        if (l > 1) {
            nums[chain[0]] -= 1;
            nums[chain.back()] -= 1;

            for (int i = 1; i < l - 1; i ++)
                nums[chain[i]] -= 2;
        }

        int ans = l - 1;

        for (int i = 1; i < l; i ++)
            edges.emplace_back(chain[i - 1], chain[i]);

        bool f1 = false, f2 = false;
        for (auto &u: nodes) {
            if (!f1) {
                f1 = true;
                nums[chain[0]] -= 1;
                edges.emplace_back(u, chain[0]);
            }
            else if (nums[chain.back()]) {
                f2 = true;
                nums[chain.back()] -= 1;
                edges.emplace_back(u, chain.back());
            }
            else {
                bool f = true;
                for (auto &v: chain) {
                    if (nums[v]) {
                        f = false;
                        nums[v] --;
                        edges.emplace_back(u, v);
                        break;
                    }
                }
                if (f) return cout << "NO", 0;
            }
        }

        cout << "YES " << ans + f1 + f2 << '\n';
        cout << n - 1 << '\n';
        for (auto &[u, v]: edges)
            cout << u + 1 << ' ' << v + 1 << '\n';
    }

    return 0;
}