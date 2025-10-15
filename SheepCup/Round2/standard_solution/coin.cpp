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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p, q, mod;
    cin >> n >> p >> q >> mod;

    int M = 200000;
    vector<int> f(M + 1, 1), c(M + 1, 0);

    for (int i = 1; i <= M; i ++) {
        int v = i;
        c[i] = c[i - 1];
        while (v % mod == 0) {
            v /= mod;
            c[i] ++;
        }
        f[i] = 1ll * v * f[i - 1] % mod;
    }

    vector<int> g(M + 1, 0);
    g[M] = quickPow(f[M], mod - 2, mod);

    for (int i = M; i > 0; i --) {
        int v = i;
        while (v % mod == 0)
            v /= mod;
        g[i - 1] = 1ll * v * g[i] % mod;
    }

    auto combi = [&] (int x, int y) {
        return c[x] > c[y] + c[x - y] ? 0 : 1ll * f[x] * g[y] % mod * g[x - y] % mod;
    };

    vector<int> v1(n), v2(n);
    vector<pair<int, int>> msk(n);

    int block = 450;

    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v1[i] = x + y - 1;
        v2[i] = x;
        msk[i] = {v1[i] / block, ((v1[i] / block) & 1) ? v2[i] : -v2[i]};
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return msk[i] < msk[j];});

    int x1 = p, x2 = q - p;

    vector<int> pw1(M + 1, 1), pw2(M + 1, 1);
    for (int i = 1; i <= M; i ++) {
        pw1[i] = 1ll * pw1[i - 1] * x1 % mod;
        pw2[i] = 1ll * pw2[i - 1] * x2 % mod;
    }

    int va = 1, vb = 1, cur = p, rev_q = quickPow(q, mod - 2, mod);
    vector<int> ans(n, -1);

    for (auto &i: order) {
        int a = v1[i], b = v2[i];

        while (va < a) {
            cur = 1ll * cur * q % mod;
            cur += 1ll * combi(va, vb - 1) * pw1[vb] % mod * pw2[va - vb + 1] % mod;
            if (cur >= mod) cur -= mod;
            va ++;
        }

        while (vb > b) {
            vb --;
            cur += 1ll * pw1[vb] * pw2[va - vb] % mod * combi(va, vb) % mod;
            if (cur >= mod) cur -= mod;
        }

        while (va > a) {
            va --;
            cur -= 1ll * combi(va, vb - 1) * pw1[vb] % mod * pw2[va - vb + 1] % mod;
            if (cur < 0) cur += mod;
            cur = 1ll * cur * rev_q % mod;
        }

        while (vb < b) {
            cur -= 1ll * pw1[vb] * pw2[va - vb] % mod * combi(va, vb) % mod;
            if (cur < 0) cur += mod;
            vb ++;
        }
        ans[i] = 1ll * cur * q % mod;
    }

    for (auto &v: ans) cout << v << '\n';

    return 0;
}