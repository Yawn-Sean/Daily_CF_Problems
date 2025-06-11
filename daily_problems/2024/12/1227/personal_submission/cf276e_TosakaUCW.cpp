#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
const int N = 1e5 + 5;
int sum[N << 2], tag[N << 2];

void pdown(int p, int l, int r) {
    if (!tag[p]) return;
    sum[ls] += tag[p] * (mid - l + 1);
    sum[rs] += tag[p] * (r - (mid + 1) + 1);
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
void pup(int p) { sum[p] = sum[ls] + sum[rs]; }
void modify(int p, int l, int r, int ql, int qr, int v) {
    if (ql <= l and r <= qr) {
        sum[p] += v * (r - l + 1);
        tag[p] += v;
        return;
    }
    pdown(p, l, r);
    if (ql <= mid) modify(ls, l, mid, ql, qr, v);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, v);
    pup(p);
}
int query(int p, int l, int r, int pos) {
    if (l == r) return sum[p];
    pdown(p, l, r);
    if (pos <= mid) return query(ls, l, mid, pos);
    else return query(rs, mid + 1, r, pos);
}

void solve() {
    int n = read();
    int q = read();
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();
        g[u].eb(v), g[v].eb(u);
    }

    vector<int> dep(n + 1);
    vector<int> dfn(n + 1); int timer = 0;
    vector<int> ch(n + 1); int chid = 0;
    vector<int> len(n + 1);

    dep[1] = 0, dfn[1] = ++timer;
    
    for (int t : g[1]) {
        int f = 1, u = t;
        ++chid;
        while (1) {
            dep[u] = dep[f] + 1;
            dfn[u] = ++timer;
            ch[u] = chid;

            if (g[u].size() == 1) break;

            int nu = g[u][0] == f ? g[u][1] : g[u][0];
            f = u, u = nu;
        }
        len[chid] = dep[u];
    }

    Fenwick<int> fwk(n);

    while (q--) {
        int opt = read();
        if (opt == 0) {
            int u = read(), x = read(), d = read();

            if (u == 1) {
                fwk.add(d, x);
            } else if (d < dep[u]) {
                modify(1, 1, n,
                    max(dfn[u] - d, dfn[u] - dep[u] + 1),
                    min(dfn[u] + d, dfn[u] + len[ch[u]] - dep[u]),
                    x);
            } else {
                fwk.add(d - dep[u], x);
                if (len[ch[u]] - dep[u] < d - 2 * dep[u] + 1)
                    continue;
                modify(1, 1, n,
                    dfn[u] + d - 2 * dep[u] + 1,
                    min(dfn[u] + d, dfn[u] + len[ch[u]] - dep[u]),
                    x);
            }

        } else {
            int u = read();
            int ans = query(1, 1, n, dfn[u]);
            int sum = fwk.rangeSum(dep[u], n);

            cout << ans + sum << '\n';
        }
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
