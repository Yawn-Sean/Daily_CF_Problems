#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree.hpp"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> perm(n);
        for (auto &x: perm) cin >> x, x --;

        vector<int> pos(n);
        for (int i = 0; i < n; i ++) pos[perm[i]] = i;

        vector<int> ans(n, 0);
        atcoder::fenwick_tree<int> fen(2 * n);

        for (int i = 0; i < n; i ++)
            if (perm[i] >= i)
                fen.add(n + perm[i], 1);
        
        for (int i = n - 1; i >= 0; i --) {
            int v = perm[i] >= i ? perm[i] : perm[i] + n;
            ans[perm[i]] = v - i - fen.sum(0, v);
            fen.add(v, 1);
        }

        for (auto &x: ans) cout << x << ' '; cout << '\n';
    }

    return 0;
}