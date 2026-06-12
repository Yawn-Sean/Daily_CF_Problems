#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include <local/dbg.h>
#else
    #define dbg(...) 42
#endif

using LL = long long;

// clang-format off
#define ai(x) using ai##x = array<int, x>;
ai(2); ai(3); ai(4); ai(5); ai(6); ai(7); ai(8); ai(9); ai(10); ai(26);
#undef ai
// clang-format on

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
template <class T>
inline bool updmx(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template <class T>
inline bool updmn(T &x, const T &y) { return y < x ? x = y, 1 : 0; }
template <class T>
inline void clr(T &x) { T().swap(x); }

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l, LL r) { return rng() % (r - l + 1) + l; }

#define D constexpr MI
#define C const
#define O operator
template <unsigned int mod>
struct MI {
    D() : v(0) {}
    template <typename T>
    D(T x) : v(x % mod) {
        if (v < 0) v += mod;
    }
    template <typename T>
    static D raw(T x) {
        MI z;
        z.v = x;
        return z;
    }
    D pow(LL n) C {
        MI x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    D inv() C { return pow(mod - 2); }
    D &O += (C MI & x) {
        if (unsigned(v += x.v) >= mod) v -= mod;
        return *this;
    }
    D &O -= (C MI & x) {
        if ((v -= x.v) < 0) v += mod;
        return *this;
    }
    D &O *= (C MI & x) {
        LL z = v;
        z *= x.v;
        v = z % mod;
        return *this;
    }
    D &O /= (C MI & x) { return *this = *this * x.inv(); }
    constexpr int val() C { return v; }
    static constexpr unsigned int umod() { return mod; }
    friend constexpr bool O == (C MI & x, C MI &y) { return x.val() == y.val(); }
#define OP(s, t) \
    friend D O s(C MI &x, C MI &y) { return MI(x) t y; }
    OP(+, +=)
    OP(-, -=)
    OP(*, *=)
    OP(/, /=)
#undef OP
private:
    int v;
};
#undef D
#undef C
#undef O

using Z = MI<int(1e9 + 7)>;
#define raw(x) Z::raw(x)

struct Node {
    Z v;
    int c;
    Node(Z _v = 0, int _c = 0) : v(_v), c(_c) {}
};
using Vec = vector<vector<Node>>;

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n, m, s, t, _X, K;
    cin >> n >> m >> s >> t >> _X >> K;
    Z X = raw(_X);
    auto adjust = [&](Vec &a) -> void {
        vector<int> b;
        b.reserve(n * n);
        for (auto &V : a)
            for (auto &[v, c] : V) {
                if (c) b.push_back(c);
            }
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        for (auto &V : a)
            for (auto &[v, c] : V) {
                if (c) c = lower_bound(all(b), c) - b.begin() + 1;
            }
    };
    auto work = [&](Vec &a, Vec &b) -> void {
        Vec c(n + 1, vector<Node>(n + 1));
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (a[i][k].c == 0) continue;
                for (int j = 0; j < n; ++j) {
                    if (b[k][j].c == 0) continue;
                    const int nc = (a[i][k].c << 12) | b[k][j].c; // (1<<12) > 2500
                    if (c[i][j].c == 0 || c[i][j].c > nc) {
                        c[i][j].c = nc;
                        c[i][j].v = a[i][k].v * X + b[k][j].v;
                    }
                }
            }
        }
        adjust(c);
        swap(a, c);
    };
    Vec ans(n + 1, vector<Node>(n + 1));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ans[--u][--v] = Node{raw(w), w};
    }
    adjust(ans);
    Vec base = ans;
    K -= 1;
    while (K) {
        if (K & 1) work(ans, base);
        work(base, base);
        K >>= 1;
        X *= X;
    }
    --s, --t;
    if (ans[s][t].c == 0)
        cout << "-1";
    else
        cout << ans[s][t].v.val();
    return 0;
}
