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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> cnt(n + 1, 0), cnt1(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            int a, f;
            cin >> a >> f;
            cnt[a] ++;
            if (f) cnt1[a] ++;
        }

        vector<int> st_range(n + 1);
        iota(st_range.begin(), st_range.end(), 0);

        sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return cnt[i] > cnt[j];});

        int ans0 = 0, ans1 = 0, pt = 0;
        priority_queue<int> pq;
        
        for (int i = n; i > 0; i --) {
            while (pt < n + 1 && cnt[st_range[pt]] >= i) {
                pq.push(cnt1[st_range[pt]]);
                pt ++;
            }
            if (pq.size()) {
                ans0 += i;
                ans1 += min(i, pq.top());
                pq.pop();
            }
        }
        cout << ans0 << ' ' << ans1 << '\n';
    }

    return 0;
}