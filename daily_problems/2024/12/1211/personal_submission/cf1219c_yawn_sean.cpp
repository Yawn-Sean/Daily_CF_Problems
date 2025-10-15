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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int l = s.size();

    auto check = [&]() -> bool {
        for (auto &c: s) {
            if (c != '9') {
                return false;
            }
        }
        return true;
    };

    if (s.size() % n || check()) {
        int k = l / n + 1;
        string ans = "1";
        ans += string(n - 1, '0');
        for (int i = 0; i < k; i ++)
            cout << ans;
    }
    else {
        string v = s.substr(0, n);
        bool flg = false;
        for (int i = 0; i < l; i += n) {
            bool tmp = true;
            for (int j = 0; j < n; j ++) {
                if (s[i + j] < v[j]) {
                    flg = true;
                    break;
                }
                else if (s[i + j] > v[j]) {
                    tmp = false;
                    break;
                }
            }
            if (!tmp || flg) break;
        }

        if (!flg) {
            for (int i = n - 1; i >= 0; i --) {
                if (v[i] == '9') v[i] = '0';
                else {
                    v[i] ++;
                    break;
                }
            }
        }
        
        for (int i = 0; i < l / n; i ++)
            cout << v;
    }

    return 0;
}