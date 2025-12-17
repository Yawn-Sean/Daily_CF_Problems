#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXV = 200000;

/* 快速幂 */
long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

/* 乘法线段树 */
struct SegTree {
    int n;
    vector<int> t;

    SegTree(int _n = 0) : n(_n), t(4 * n, 1) {}

    void update(int p, int v, int id, int l, int r) {
        if (l + 1 == r) {
            t[id] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (p < m) update(p, v, id << 1, l, m);
        else update(p, v, id << 1 | 1, m, r);
        t[id] = 1LL * t[id << 1] * t[id << 1 | 1] % MOD;
    }

    void set(int p, int v) { update(p, v, 1, 0, n); }

    int query(int ql, int qr, int id, int l, int r) const {
        if (ql <= l && r <= qr) return t[id];
        if (qr <= l || r <= ql) return 1;
        int m = (l + r) >> 1;
        return 1LL * query(ql, qr, id << 1, l, m)
                    * query(ql, qr, id << 1 | 1, m, r) % MOD;
    }

    int prod(int l, int r) const { return query(l, r, 1, 0, n); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> spf(MAXV + 1);
    for (int i = 2; i <= MAXV; ++i)
        if (!spf[i])
            for (int j = i; j <= MAXV; j += i)
                spf[j] = i;
    vector<int> fact(MAXV + 1), ifact(MAXV + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXV; ++i)
        fact[i] = 1LL * fact[i - 1] * i % MOD;

    ifact[MAXV] = mod_pow(fact[MAXV], MOD - 2);
    for (int i = MAXV; i; --i)
        ifact[i - 1] = 1LL * ifact[i] * i % MOD;

    auto inv = [&](int x) {
        return 1LL * fact[x - 1] * ifact[x] % MOD;
    };

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<pair<int, int>>> qs(n);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        qs[l].emplace_back(i, r);
    }

    vector<int> last(MAXV + 1, n);
    SegTree seg(n);
    vector<int> ans(q);

    for (int i = n - 1; i >= 0; --i) {
        int x = a[i];
        vector<int> primes;

        while (x > 1) {
            int p = spf[x];
            primes.push_back(p);
            while (x % p == 0) x /= p;
        }

        int cur = 1;
        for (int p : primes) {
            if (last[p] < n) {
                int v = 1LL * seg.prod(last[p], last[p] + 1) * inv(p) % MOD;
                seg.set(last[p], v);
            }
            cur = 1LL * cur * p % MOD;
            last[p] = i;
        }

        seg.set(i, cur);

        for (auto &[id, r] : qs[i])
            ans[id] = seg.prod(0, r + 1);
    }

    for (int x : ans)
        cout << x << '\n';

    return 0;
}
