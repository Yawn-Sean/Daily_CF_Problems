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

    auto query = [&] (string s) -> pair<int, int> {
        cout << s << endl;
        pair<int, int> ans;
        cin >> ans.first >> ans.second;
        if (ans.first == 4) exit(0);
        return ans;
    };

    string ans;

    for (int i = 0; i < 10; i ++) {
        auto v = query(string(4, '0' + i));
        ans += string(v.first + v.second, '0' + i);
    }

    while (true) {
        query(ans);
        next_permutation(ans.begin(), ans.end());
    }

    return 0;
}