#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

    vector<pair<int, int>> p0, p1;
    for (int i = 1; i <= n; i ++) {
        int c, v;
        cin >> c >> v;
        if (c) p1.emplace_back(v, i);
        else p0.emplace_back(v, i);
    }

    for (int i = 0; i < n - 1; i ++) {
        auto [v0, idx0] = p0.back(); p0.pop_back();
        auto [v1, idx1] = p1.back(); p1.pop_back();
        if (v0 <= v1 && !p0.empty()) {
            cout << idx0 << ' ' << idx1 << ' ' << v0 << '\n';
            p1.emplace_back(v1 - v0, idx1);
        }
        else {
            cout << idx0 << ' ' << idx1 << ' ' << v1 << '\n';
            p0.emplace_back(v0 - v1, idx0);
        }
    }

    return 0;
}