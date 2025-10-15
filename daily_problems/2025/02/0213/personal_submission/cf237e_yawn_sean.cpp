#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
#include "atcoder/mincostflow"
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

    string s;
    cin >> s;

    int target = s.size();
    vector<int> cnt(26, 0);

    for (auto &c: s)
        cnt[c - 'a'] ++;
    
    int n;
    cin >> n;

    atcoder::mcf_graph<int, int> mcf(n + 28);
    int src = n + 26, dst = n + 27;

    for (int i = 0; i < 26; i ++) {
        if (cnt[i]) {
            mcf.add_edge(n + i, dst, cnt[i], 0);
        }
    }

    for (int i = 0; i < n; i ++) {
        string si;
        int ai;
        cin >> si >> ai;

        mcf.add_edge(src, i, ai, i + 1);
        
        for (int j = 0; j < 26; j ++)
            cnt[j] = 0;
        
        for (auto &c: si)
            cnt[c - 'a'] ++;
        
        for (int j = 0; j < 26; j ++) {
            if (cnt[j]) {
                mcf.add_edge(i, n + j, cnt[j], 0);
            }
        }
    }

    auto ans = mcf.flow(src, dst);
    cout << (ans.first == target ? ans.second : -1);

    return 0;
}