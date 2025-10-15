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

    auto check1 = [&] (char c) -> bool {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_');
    };

    auto check2 = [&] (char c) -> bool {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    };

    auto check3 = [&] (char c) -> bool {
        return (c >= 'a' && c <= 'z');
    };

    string s;
    cin >> s;

    int n = s.size();
    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        if (s[i] == '@') {
            int l = i, cl = 0;

            while (l > 0 && check1(s[l - 1])) {
                l --;
                cl += check3(s[l]);
            }

            int r = i;
            while (r + 1 < n && check2(s[r + 1]))
                r ++;
            
            if (r > i && r + 1 < n && s[r + 1] == '.') {
                r ++;
                int nr = r, cr = 0;

                while (nr + 1 < n && check3(s[nr + 1]))
                    nr ++, cr ++;
                
                ans += 1ll * cl * cr;
            }
        }
    }

    cout << ans;

    return 0;
}