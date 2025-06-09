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

    int m, M = 1e5;
    cin >> m;

    vector<int> ar_pref, notes;
    vector<long long> lengths = {0};
    
    while (m --) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;

            if (ar_pref.size() < M)
                ar_pref.emplace_back(x);
            
            notes.emplace_back(-x);
            lengths.emplace_back(lengths.back() + 1);
        }
        else {
            int l, c;
            cin >> l >> c;

            for (int i = 0; i < l * c && ar_pref.size() < M; i ++)
                ar_pref.emplace_back(ar_pref[i % l]);
            
            notes.emplace_back(l);
            lengths.emplace_back(lengths.back() + l * c);
        }
    }

    int q;
    cin >> q;

    while (q --) {
        long long x;
        cin >> x;

        int p = lower_bound(lengths.begin(), lengths.end(), x) - lengths.begin() - 1;
        cout << (notes[p] < 0 ? -notes[p] : ar_pref[(x - 1 - lengths[p]) % notes[p]]) << ' ';
    }

    return 0;
}