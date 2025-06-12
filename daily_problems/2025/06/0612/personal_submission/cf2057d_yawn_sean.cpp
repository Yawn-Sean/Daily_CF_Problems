#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

#include "atcoder/segtree"

typedef array<int, 5> node;

int inf = 1e9 + 1000000;

node op(node a, node b) {
    node res;
    res[0] = min(a[0], b[0]);
    res[1] = max(a[1], b[1]);
    res[2] = min(a[2], b[2]);
    res[3] = max(a[3], b[3]);
    res[4] = max(a[4], b[4]);
    res[4] = max(res[4], b[1] - a[0]);
    res[4] = max(res[4], a[3] - b[2]);
    return res;
}

node e() {
    return {inf, -inf, inf, -inf, 0};
}

node e1(int idx, int val) {
    return {val - idx, val - idx, val + idx, val + idx, 0};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, q;
        cin >> n >> q;

        vector<node> vals(n);
        for (int i = 0; i < n; i ++) {
            int v;
            cin >> v;
            vals[i] = e1(i, v);
        }

        atcoder::segtree<node, op, e> seg(vals);

        cout << seg.all_prod()[4] << '\n';
        while (q --) {
           int idx, val;
           cin >> idx >> val;
           idx --;
           seg.set(idx, e1(idx, val));
           cout << seg.all_prod()[4] << '\n'; 
        }
    }

    return 0;
}