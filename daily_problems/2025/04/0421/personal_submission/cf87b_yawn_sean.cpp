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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    int n;
    cin >> n;

    map<string, int> mp;
    mp["void"] = 0;
    mp["errtype"] = -100000;

    while (n --) {
        string op;
        cin >> op;
        if (op[4] == 'd') {
            string v1, v2;
            cin >> v1 >> v2;

            int l = 0, r = v1.size() - 1, cur = 0;

            while (v1[l] == '&')
                l ++, cur --;
            
            while (v1[r] == '*')
                r --, cur ++;
            
            string orig = v1.substr(l, r - l + 1);

            if (mp.find(orig) == mp.end())
                mp[orig] = -100000;
            
            int nval = mp[orig] + cur;
            mp[v2] = (nval >= 0 ? nval : -100000);
        }
        else {
            string v;
            cin >> v;

            int l = 0, r = v.size() - 1, cur = 0;

            while (v[l] == '&')
                l ++, cur --;
            
            while (v[r] == '*')
                r --, cur ++;
            
            string orig = v.substr(l, r - l + 1);

            if (mp.find(orig) == mp.end() || mp[orig] + cur < 0) cout << "errtype";
            else cout << "void" << string(mp[orig] + cur, '*');
            cout << '\n';
        }
    }

    return 0;
}