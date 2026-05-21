#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MX = 2e5 + 1;
ll F[MX];      // 预处理阶乘
ll INV_F[MX];  // 预处理逆元
ll qpow(ll x, int n) {
    ll res = 1;
    for (; n; n >>= 1) {
        if (n % 2) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}
auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) F[i] = F[i - 1] * i % MOD;  // 预处理阶乘
    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }  // 预处理逆元
    return 0;
}();
// 计算C(n,m),即从n个数中取m个数
ll comb(int n, int m) { return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD; }
void solve() {
    int n, k, x, y;
    cin >> n >> k;
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vi dep(n);
    vi siz(n);
    vl cnt(n);
    vl res(n);
    auto dfs1 = [&](this auto&& dfs1, int x, int pa, int d) -> void {
        dep[x] = d;
        int tem = 1;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            dfs1(p, x, d + 1);
            tem += siz[p];
        }
        siz[x] = tem;
        cnt[x] = comb(tem, k);
        for (int& p : ma[x]) {
            cnt[x] = (cnt[x] - comb(siz[p], k) + MOD) % MOD;
        }
        return;
    };
    dfs1(0, -1, 0);
    rep(i, 0, n - 1) res[0] = (res[0] + dep[i] * cnt[i] % MOD) % MOD;
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        for (int& p : ma[x]) {
            if (p == pa) continue;
            res[p] = (res[x] + comb(n - siz[p], k) - comb(siz[p], k) + MOD) % MOD;
            dfs2(p, x);
        }
        return;
    };
    dfs2(0, -1);
    rep(i, 0, n - 1) cout << res[i] << ' ';
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
