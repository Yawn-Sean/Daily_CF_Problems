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

    vector<int> cnt(n + 1, 0);
    map<pair<int, int>, vector<int>> path;

    for (int i = 0; i < n - 2; i ++) {
        vector<int> tmp(3);
        for (auto &x: tmp) cin >> x;
        sort(tmp.begin(), tmp.end());

        int u = tmp[0], v = tmp[1], w = tmp[2];
        cnt[u] ++;
        cnt[v] ++;
        cnt[w] ++;

        path[{u, v}].emplace_back(w);
        path[{u, w}].emplace_back(v);
        path[{v, w}].emplace_back(u);
    }

    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 1) {
            vector<int> ans = {i};

            for (auto &[k, _]: path) {
                auto [u, v] = k;
                if (u == i && cnt[v] == 2) {
                    ans.emplace_back(v);
                    break;
                }
                if (v == i && cnt[u] == 2) {
                    ans.emplace_back(u);
                    break;
                }
            }

            for (int j = 0; j < n - 2; j ++) {
                int u = ans[j], v = ans[j + 1];
                if (u > v) swap(u, v);

                for (auto &w: path[{u, v}]) {
                    if (j == 0 || ans[j - 1] != w) {
                        ans.emplace_back(w);
                        break;
                    }
                }
            }

            for (auto &x: ans) cout << x << ' ';
            break;
        }
    }

    return 0;
}