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

    int n, q;
    cin >> n >> q;

    vector<vector<int>> ops(n + 1);

    for (int i = 1; i <= q; i ++) {
        char c;
        int idx;
        cin >> c >> idx;

        if (c == '+') ops[idx].emplace_back(i);
        else {
            if (ops[idx].empty()) ops[idx].emplace_back(0);
            ops[idx].emplace_back(-i);
        }
    }

    vector<int> diff(q + 2, 0);

    for (int i = 0; i <= n; i ++) {
        if (ops[i].size() & 1) ops[i].emplace_back(-(q + 1));

        for (int j = 0; j < ops[i].size(); j ++) {
            if (j & 1) diff[-ops[i][j]] --;
            else diff[ops[i][j]] ++;
        }
    }

    int l = 0;
    for (int i = 0; i < q + 1; i ++) {
        if (diff[i]) l ++;
        diff[i + 1] += diff[i];
    }

    vector<int> ans;
    for (int i = 1; i <= n; i ++) {
        if (ops[i].empty()) ans.emplace_back(i);
        else {
            int cur = l;
            for (auto &x: ops[i]) cur += x;
            if (!cur) ans.emplace_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (auto &x: ans) cout << x << ' ';

    return 0;
}