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

    int M = 1e7;
    vector<int> prime_factor(M + 1);
    iota(prime_factor.begin(), prime_factor.end(), 0);

    for (int i = 2; i <= M; i ++) {
        if (prime_factor[i] == i) {
            for (int j = i; j <= M; j += i) {
                prime_factor[j] = i;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (auto &x: nums1) cin >> x;
    for (auto &x: nums2) cin >> x;

    vector<int> cnt1(M + 1, 0), cnt2(M + 1, 0);

    for (int i = 0; i < n; i ++) {
        int x = nums1[i];
        while (x > 1) {
            cnt1[prime_factor[x]] ++;
            x /= prime_factor[x];
        }
    }

    for (int i = 0; i < m; i ++) {
        int x = nums2[i];
        while (x > 1) {
            cnt2[prime_factor[x]] ++;
            x /= prime_factor[x];
        }
    }

    for (int i = 0; i <= M; i ++) {
        cnt1[i] = min(cnt1[i], cnt2[i]);
        cnt2[i] = cnt1[i];
    }

    for (int i = 0; i < n; i ++) {
        int x = nums1[i];
        while (x > 1) {
            if (cnt1[prime_factor[x]]) {
                cnt1[prime_factor[x]] --;
                nums1[i] /= prime_factor[x];
            }
            x /= prime_factor[x];
        }
    }

    for (int i = 0; i < m; i ++) {
        int x = nums2[i];
        while (x > 1) {
            if (cnt2[prime_factor[x]]) {
                cnt2[prime_factor[x]] --;
                nums2[i] /= prime_factor[x];
            }
            x /= prime_factor[x];
        }
    }

    cout << n << ' ' << m << '\n';
    for (auto &v: nums1) cout << v << ' ';
    cout << '\n';
    for (auto &v: nums2) cout << v << ' ';
    cout << '\n';

    return 0;
}