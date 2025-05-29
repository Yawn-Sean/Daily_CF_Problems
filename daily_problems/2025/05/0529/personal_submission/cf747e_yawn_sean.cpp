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

    string s;
    cin >> s;

    string tmp;
    vector<string> strs;

    for (auto &c: s) {
        if (c == ',') {
            strs.emplace_back(tmp);
            tmp = "";
        }
        else tmp += c;
    }

    strs.emplace_back(tmp);

    int n = strs.size();

    vector<vector<string>> ans;
    vector<int> cur = {10000000};

    for (int i = 0; i < n; i += 2) {
        int v = stoi(strs[i + 1]);

        while (cur.back() == 0) cur.pop_back();

        if (cur.size() - 1 == ans.size())
            ans.push_back(vector<string>());
        
        ans[cur.size() - 1].emplace_back(strs[i]);
        cur.back() -= 1; cur.emplace_back(v);
    }

    cout << ans.size() << '\n';
    for (auto &x: ans) {
        for (int i = 0; i < x.size(); i ++) {
            if (i) cout << ' ';
            cout << x[i];
        }
        cout << '\n';
    }

    return 0;
}