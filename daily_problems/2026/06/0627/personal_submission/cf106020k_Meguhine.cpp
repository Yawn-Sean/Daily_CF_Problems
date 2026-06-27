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

constexpr int N = 20;
constexpr LL inf = 1e16;
LL D[N * 2 + 5], F[N * 2 + 5][N * 2 + 5];

auto __init_F = []() -> bool {
    D[0] = 1, D[1] = 0;
    for (int n = 2; n < N; ++n) {
        D[n] = (n - 1) * (D[n - 1] + D[n - 2]);
        if (D[n] > inf) {
            for (int m = n; m < N; ++m) D[m] = inf;
            break;
        }
    }
    memset(F, -1, sizeof(F));
    auto dfs = [&](auto &&self, int n, int m) -> void {
        if (F[n][m] != -1) return;
        if (!m) return (void)(F[n][m] = D[n]);
        self(self, n, m - 1);
        self(self, n + 1, m - 1);
        F[n][m] = F[n][m - 1] + F[n + 1][m - 1];
        if (F[n][m] > inf) F[n][m] = inf;
    };
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            dfs(dfs, i, j);
        }
    }
    return 1;
}();

void solve() {
    int n;
    LL K;
    cin >> n >> K;
    vector<int> ans(n + 1);
    int p = 1;
    while (n - p >= N) {
        if (p & 1)
            ans[p] = p + 1;
        else
            ans[p] = p - 1;
        ++p;
    }
    vector<int> nvis;
    int nn = n - p + 1, mm = 0;
    if (p & 1)
        for (int x = p; x <= n; ++x) nvis.push_back(x);
    else {
        --nn, ++mm;
        nvis.push_back(p - 1);
        for (int x = p + 1; x <= n; ++x) nvis.push_back(x);
    }
    dbg(nvis, p, K);
    for (; p <= n; ++p) {
        const bool has_p = binary_search(all(nvis), p);
        for (auto it = nvis.begin(); it != nvis.end(); ++it) {
            const int x = *it;
            if (x == p) continue;
            int tn = nn;
            int tm = mm;
            if (x < p)
                --tm;
            else
                --tn;
            if (has_p) --tn, ++tm;
            dbg(p, x, K, tn, tm);
            dbg("\t", F[tn][tm]);
            const LL cnt = F[tn][tm];
            if (K > cnt)
                K -= cnt;
            else {
                ans[p] = x;
                nn = tn, mm = tm;
                nvis.erase(it);
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}
int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/*
不难发现, 这道题的关键是求如下函数 F(n, m):
当有 n 个位置需要"错开", m 个位置"无所谓"的时候, 符合条件的映射数有多少种 ???
类似于对错排的推导, 我们不妨考虑最后一个"无所谓"的位置:
- 在原地不懂, F(n, m-1)
- 换个地方待, F(n+1, m-1)
所以 F(n, m) := F(n, m-1) + F(n+1, m-1)
然后又显然有 F(n, 0) := D(n), 这就是原本的错排
~~然后我就不会了~~, 因为计算 F 需要 O(n^2)
~~然后看了羊总的提示~~ 哈哈哈哈, 直接暴力就可以了
*/
