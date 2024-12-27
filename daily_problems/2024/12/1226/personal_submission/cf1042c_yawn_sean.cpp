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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;

    vector<int> neg, pos, zero;
    
    for (int i = 0; i < n; i ++) {
        if (nums[i] > 0) pos.emplace_back(i);
        else if (nums[i] < 0) neg.emplace_back(i);
        else zero.emplace_back(i);
    }

    sort(neg.begin(), neg.end(), [&] (int i, int j) {return nums[i] > nums[j];});

    while (neg.size() > 1) {
        int i1 = neg.back();
        neg.pop_back();
        int i2 = neg.back();
        neg.pop_back();
        pos.emplace_back(i2);
        cout << 1 << ' ' << i1 + 1 << ' ' << i2 + 1 << '\n';
    }

    while (pos.size() > 1) {
        int i1 = pos.back();
        pos.pop_back();
        int i2 = pos.back();
        pos.pop_back();
        pos.emplace_back(i2);
        cout << 1 << ' ' << i1 + 1 << ' ' << i2 + 1 << '\n';
    }

    while (zero.size() > 1) {
        int i1 = zero.back();
        zero.pop_back();
        int i2 = zero.back();
        zero.pop_back();
        zero.emplace_back(i2);
        cout << 1 << ' ' << i1 + 1 << ' ' << i2 + 1 << '\n';
    }

    if (neg.size() == 0) {
        if (zero.size() > 0 && pos.size() > 0) cout << 2 << ' ' << zero[0] + 1 << '\n';
    }
    else {
        if (zero.size()) {
            cout << 1 << ' ' << neg[0] + 1 << ' ' << zero[0] + 1 << '\n';
            if (pos.size()) cout << 2 << ' ' << zero[0] + 1 << '\n';
        }
        else cout << 2 << ' ' << neg[0] + 1 << '\n';
    }

    return 0;
}