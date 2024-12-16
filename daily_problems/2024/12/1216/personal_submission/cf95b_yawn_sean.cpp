#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

    string s;
    cin >> s;
    int n = s.size();

    if (n & 1) {
        int x = (n + 1) / 2;
        cout << string(x, '4') << string(x, '7');
    }
    else {
        int x = n / 2;
        if (string(x, '7') + string(x, '4') < s)
            cout << string(x + 1, '4') << string(x + 1, '7');
        else {
            string ans = s;
            int c4 = x, c7 = x;
            bool flg = false;

            for (int i = 0; i < n; i ++) {
                if (flg) {
                    if (c4) ans[i] = '4', c4 --;
                    else ans[i] = '7', c7 --;
                }
                else {
                    if (s[i] == '4') {
                        if (c4) ans[i] = '4', c4 --;
                        else ans[i] = '7', c7 --, flg = true;
                    }
                    else if (s[i] > '4' && s[i] <= '7' && c7) {
                        if (s[i] != '7') flg = true;
                        ans[i] = '7', c7 --;
                    }
                    else if (s[i] > '4') {
                        flg = true;
                        for (int j = i - 1; j >= 0; j --) {
                            if (ans[j] == '4') {
                                if (c7) {
                                    c4 ++, c7 --, ans[j] = '7';
                                    i = j;
                                    break;
                                }
                                else c4 ++;
                            }
                            else c7 ++;
                        }
                    }
                    else {
                        flg = true;
                        if (c4) ans[i] = '4', c4 --;
                        else ans[i] = '7', c7 --;
                    }
                }
            }
            cout << ans;
        }
    }

    return 0;
}