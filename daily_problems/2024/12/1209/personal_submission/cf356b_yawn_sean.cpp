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

    long long n, m;
    cin >> n >> m;
    
    string s1, s2;
    cin >> s1 >> s2;

    int k1 = s1.size(), k2 = s2.size();

    int g = gcd(k1, k2);
    long long ans = 0;

    for (int i = 0; i < g; i ++) {
        map<char, int> c;
        for (int j = i; j < k1; j += g)
            c[s1[j]] ++;
        for (int j = i; j < k2; j += g)
            ans += c[s2[j]];
    }

    cout << (n * k1 - gcd(n, m) * ans);

    return 0;
}