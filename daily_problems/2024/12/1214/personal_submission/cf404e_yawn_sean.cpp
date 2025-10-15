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

    map<char, int> mp;
    mp['L'] = -1, mp['R'] = 1;

    string s;
    cin >> s;

    int n = s.size();

    int l, r, cur;
    l = 0, r = 0, cur = 0;

    for (int i = 0; i < n - 1; i ++) {
        cur += mp[s[i]];
        l = min(cur, l);
        r = max(cur, r);
    }

    cur += mp[s[n - 1]];
    if (cur < l || cur > r)
        return cout << 1, 0;
    
    if (s[n - 1] == 'L') {
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            l = 0, cur = 0;
            for (int i = 0; i < n - 1; i ++) {
                cur = min(cur + mp[s[i]], mid - 1);
                l = min(cur, l);
            }
            cur += mp[s[n - 1]];
            if (cur < l) left = mid + 1;
            else right = mid - 1;
        }
        cout << right;
    }
    else {
        int left = -n, right = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            r = 0, cur = 0;
            for (int i = 0; i < n - 1; i ++) {
                cur = max(cur + mp[s[i]], mid + 1);
                r = max(r, cur);
            }
            cur += mp[s[n - 1]];
            if (cur > r) right = mid - 1;
            else left = mid + 1;
        }
        cout << -left;
    }

    return 0;
}