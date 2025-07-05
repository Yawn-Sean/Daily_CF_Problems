#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu.hpp"

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

        atcoder::dsu uf(n + 1);
        vector<int> deg(n + 1, 0);
        set<pair<int, int>> st;

        int total = n;

        for (int i = 1; i <= n; i ++) {
            int x = i, y;
            cin >> y;
            if (x > y) swap(x, y);

            if (st.find({x, y}) == st.end()) {
                st.insert({x, y});
                deg[x] ++, deg[y] ++;
                total -= uf.merge(x, y);
            }
        }

        int cnt = 0;
        for (auto &v: deg) cnt += (v == 1);

        cout << min(total, total + 1 - cnt / 2) << ' ' << total << '\n';
    }

    return 0;
}