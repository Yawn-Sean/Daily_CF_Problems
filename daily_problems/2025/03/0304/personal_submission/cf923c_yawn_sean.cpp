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

int zero[10000000], one[10000000], cnt[10000000], pt = 0;

void insert_value(int x) {
    int cur = 0;
    for (int i = 29; i >= 0; i --) {
        if (x >> i & 1) {
            if (!one[cur]) one[cur] = ++pt;
            cur = one[cur];
        }
        else {
            if (!zero[cur]) zero[cur] = ++pt;
            cur = zero[cur];
        }
        cnt[cur] ++;
    }
}

void delete_value(int x) {
    int cur = 0;
    for (int i = 29; i >= 0; i --) {
        cur = (x >> i & 1 ? one[cur] : zero[cur]);
        cnt[cur] --;
    }
}

int min_xor_value(int x) {
    int cur = 0, ans = 0;
    for (int i = 29; i >= 0; i --) {
        if (x >> i & 1) {
            if (one[cur] && cnt[one[cur]]) cur = one[cur];
            else cur = zero[cur], ans |= 1 << i;
        }
        else {
            if (zero[cur] && cnt[zero[cur]]) cur = zero[cur];
            else cur = one[cur], ans |= 1 << i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    for (int i = 0; i < n; i ++) {
        int v;
        cin >> v;
        insert_value(v);
    }

    for (auto &x: nums) {
        int res = min_xor_value(x);
        delete_value(x ^ res);
        cout << res << ' ';
    }

    return 0;
}