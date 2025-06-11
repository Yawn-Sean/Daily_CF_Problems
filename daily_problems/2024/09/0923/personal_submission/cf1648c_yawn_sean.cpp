#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        p++;
        while (p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M = 2e5 + 5, mod = 998244353;
    vector<int> f(M + 1, 1), g(M + 1, 1);

    for (int i = 1; i <= M; i ++)
        f[i] = 1ll * i * f[i - 1] % mod; 
    
    g[M] = quickPow(f[M], mod - 2, mod);

    for (int i = M; i >= 1; i --)
        g[i - 1] = 1ll * i * g[i] % mod;

    int n, m;
    cin >> n >> m;

    vector<int> cnt(M);
    fenwick_tree<int> fen(M);

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
        fen.add(x, 1);
    }

    int cur = f[n];

    for (auto &x: cnt)
        cur = 1ll * cur * g[x] % mod;

    int ans = 0;

    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;

        if (i >= n) {
            ans ++;
            if (ans == mod) ans = 0;
            break;
        }

        cur = 1ll * cur * f[n - i - 1] % mod * g[n - i] % mod;
        ans += 1ll * cur * fen.sum(0, x) % mod;
        if (ans >= mod) ans -= mod;

        if (cnt[x] == 0) break;
        cur = 1ll * cur * cnt[x] % mod;
        cnt[x] --;
        fen.add(x, -1);
    }
    cout << ans;

    return 0;
}