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

    int n, r, c;
    cin >> n >> r >> c;

    vector<string> strs(n);
    for (auto &s: strs) cin >> s;

    vector<int> notes(n + 1, 0);
    int left = 0, right = 0, total = 0;

    while (left < n) {
        while (right < n && right - left + total + (int)strs[right].size() <= c) {
            total += strs[right].size();
            right ++;
        }

        notes[left] = right;
        total -= strs[left].size();
        left ++;
    }

    notes[n] = n;

    vector<int> tmp = notes, cur(n + 1);
    iota(cur.begin(), cur.end(), 0);

    for (int i = 0; i < 20; i ++) {
        if (r >> i & 1) {
            for (int j = 0; j <= n; j ++)
                cur[j] = tmp[cur[j]];
        }

        vector<int> ntmp(n + 1);
        for (int j = 0; j <= n; j ++)
            ntmp[j] = tmp[tmp[j]];
        
        swap(ntmp, tmp);
    }

    int ans = -1, idx = -1;

    for (int i = 0; i < n; i ++) {
        if (cur[i] - i > ans) {
            ans = cur[i] - i;
            idx = i;
        }
    }

    while (r --) {
        if (notes[idx] > idx) {
            for (int i = idx; i < notes[idx]; i ++)
                cout << strs[i] << (i == notes[idx] - 1 ? '\n' : ' ');
            idx = notes[idx];
        }
    }

    return 0;
}