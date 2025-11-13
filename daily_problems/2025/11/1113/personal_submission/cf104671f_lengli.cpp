#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTreeAnd {
    int n;
    vector<ll> seg;
    SegTreeAnd() { n = 0; }
    void init(int sz, ll identity = -1LL) {
        n = 1;
        while (n < sz) n <<= 1;
        seg.assign(2 * n, identity);
    }
    void build(const vector<ll>& a, ll identity = -1LL) {
        int sz = (int)a.size();
        init(sz, identity);
        for (int i = 0; i < sz; ++i) seg[n + i] = a[i];
        for (int i = n - 1; i > 0; --i) seg[i] = seg[i<<1] & seg[i<<1|1];
    }
    ll prod(int l, int r, ll identity = -1LL) {
        ll resL = identity, resR = identity;
        l += n; r += n;
        while (l < r) {
            if (l & 1) resL &= seg[l++];
            if (r & 1) resR &= seg[--r];
            l >>= 1; r >>= 1;
        }
        return resL & resR;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    long long k;
    if (!(cin >> n >> k >> q)) return 0;

    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<ll> tmp(n, -1LL);
    for (int i = 0; i < n; ++i) {
        if ((nums[i] & k) == k) tmp[i] = nums[i];
    }

    SegTreeAnd seg;
    seg.build(tmp, -1LL);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        ll res = seg.prod(l, r + 1);
        if (res == k) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
