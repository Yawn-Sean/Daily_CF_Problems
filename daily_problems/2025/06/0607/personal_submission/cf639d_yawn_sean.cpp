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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, b, c;
    cin >> n >> k >> b >> c;
    b = min(b, 5 * c);

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;
    sort(nums.begin(), nums.end());

    long long ans = 1e18;

    for (int i = 0; i < 5; i ++) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long total = 0;

        for (int v: nums) {
            int cur = 0;
            while ((v - i) % 5)
                cur += c, v ++;
            
            v = (v - i) / 5;

            pq.push(1ll * v * b - cur);
            total += 1ll * v * b - cur;

            while (pq.size() > k) {
                total -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) ans = min(ans, 1ll * v * b * k - total);
        }
    }

    cout << ans;

    return 0;
}