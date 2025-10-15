#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int n, m;
    cin >> n >> m;

    vector<int> c1, c2;
    vector<long long> v1, v2;

    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        
        int c, v;
        c = s.back() - 'a';
        v = stoi(s.substr(0, s.size() - 2));
        
        if (!c1.empty() && c1.back() == c) v1.back() += v;
        else c1.emplace_back(c), v1.emplace_back(v);
    }

    for (int i = 0; i < m; i ++) {
        string s;
        cin >> s;
        
        int c, v;
        c = s.back() - 'a';
        v = stoi(s.substr(0, s.size() - 2));
        
        if (!c2.empty() && c2.back() == c) v2.back() += v;
        else c2.emplace_back(c), v2.emplace_back(v);
    }

    long long ans = 0;

    if (c2.size() == 1) {
        for (int i = 0; i < v1.size(); i ++) {
            if (c1[i] == c2[0]) {
                ans += max(0ll, v1[i] - v2[0] + 1);
            }
        }
    }
    else if (c2.size() == 2) {
        for (int i = 1; i < v1.size(); i ++)
            if (c1[i] == c2[1] && v1[i] >= v2[1] && c1[i - 1] == c2[0] && v1[i - 1] >= v2[0])
                ans ++;
    }
    else {
        vector<long long> tmp;
        for (int i = 1; i + 1 < c2.size(); i ++)
            tmp.emplace_back(v2[i] * 26 + c2[i]);
        tmp.emplace_back(-1);
        for (int i = 0; i < c1.size(); i ++)
            tmp.emplace_back(v1[i] * 26 + c1[i]);
        
        vector<int> kmp(tmp.size());
        int j = 0;
        for (int i = 1; i < tmp.size(); i ++) {
            while (j && tmp[j] != tmp[i])
                j = kmp[j - 1];
            if (tmp[j] == tmp[i]) j ++;
            kmp[i] = j;
        }

        for (int i = 0; i < c1.size(); i ++) {
            if (kmp[i + c2.size() - 1] == c2.size() - 2) {
                int i1 = i - c2.size() + 2;
                int i2 = i + 1;

                if (i1 >= 0 && c1[i1] == c2[0] && v1[i1] >= v2[0] && i2 < c1.size() && c1[i2] == c2.back() && v1[i2] >= v2.back())
                    ans ++;
            }
        }
    }

    cout << ans;

    return 0;
}