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

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> odd, even;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (x & 1) odd.emplace_back(x);
        else even.emplace_back(x);
    }

    if (odd.size() < k - p) cout << "NO";
    else if ((odd.size() - (k - p)) & 1) cout << "NO";
    else if ((odd.size() - (k - p)) / 2 + even.size() < p) cout << "NO";
    else {
        cout << "YES\n";
        vector<vector<int>> ars;

        for (int i = 0; i < k - p; i ++) {
            ars.push_back(vector<int>(0));
            ars.back().emplace_back(odd.back());
            odd.pop_back();
        }

        for (int i = 0; i < p; i ++) {
            if (even.size()) {
                ars.push_back(vector<int>(0));
                ars.back().emplace_back(even.back());
                even.pop_back();
            }
            else {
                ars.push_back(vector<int>(0));
                ars.back().emplace_back(odd.back());
                odd.pop_back();
                ars.back().emplace_back(odd.back());
                odd.pop_back();
            }
        }

        ars[0].insert(ars[0].end(), odd.begin(), odd.end());
        ars[0].insert(ars[0].end(), even.begin(), even.end());

        for (auto &ar: ars) {
            cout << ar.size() << ' ';
            for (auto &x: ar) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}