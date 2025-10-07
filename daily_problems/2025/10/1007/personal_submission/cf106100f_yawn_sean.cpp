#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"

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

    int n;
    cin >> n;

    vector<int> v1(n), v2(n);
    for (auto &x: v1) cin >> x;
    for (auto &x: v2) cin >> x;

    for (int i = 0; i < n; i ++) {
        v1[i] -= i;
        v2[i] -= i;
    }

    map<int, vector<int>> mp1;

    for (int i = 0; i < n; i ++) {
        mp1[v1[i]].emplace_back(i);
    }

    for (int i = n - 1; i >= 0; i --) {
        auto pt = mp1.find(v2[i]);
        if (pt == mp1.end() || pt->second.empty()) return cout << -1, 0;
        v2[i] = pt->second.back();
        pt->second.pop_back();
    }

    atcoder::fenwick_tree<int> fen(n);
    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        ans += fen.sum(v2[i], n);
        fen.add(v2[i], 1);
    }

    cout << ans;

    return 0;
}