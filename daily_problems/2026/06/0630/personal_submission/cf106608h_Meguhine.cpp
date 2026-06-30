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

constexpr int N = 1e6 + 5;
vector<int> factors[N];
bool __init_factors = []() -> bool {
    factors[1].push_back(1);
    for (int x = 2; x < N; ++x) {
        factors[x].push_back(1);
        for (int y = x; y < N; y += x) factors[y].push_back(x);
    }
    return 1;
}();

bitset<N> notP;
int mu[N], mn_p[N];
vector<int> prime;
auto __init_prime = []() -> bool { // init [1, N)
    mu[1] = mn_p[1] = notP[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!notP[i]) {
            prime.push_back(mn_p[i] = i);
            mu[i] = -1;
        }
        for (const int &p : prime) {
            if (i > (N - 1) / p) break;
            int j = i * p;
            notP[j] = 1, mn_p[j] = p;
            if (i % p == 0) {
                mu[j] = 0;
                break;
            }
            mu[j] = -mu[i];
        }
    }
    return 1;
}();

int cnt[N];
void solve() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        for (auto d : factors[x]) ++cnt[d];
    }
    for (int op, i, g; Q--;) {
        cin >> op >> i >> g;
        --i;
        if (op == 1) {
            const int x = a[i];
            if (x % g) {
                cout << "0\n";
                continue;
            }
            int y = x / g;
            int ans = 0;
            for (auto d : factors[y]) {
                if (!mu[d]) continue;
                const int z = d * g;
                if (z < N)
                    ans += mu[d] * cnt[d * g];
                else
                    break;
            }
            if (x == g) ans -= 1;
            cout << ans << '\n';
        } else {
            for (auto d : factors[a[i]]) --cnt[d];
            for (auto d : factors[g]) ++cnt[d];
            a[i] = g;
        }
    }
    for (auto x : a)
        if (cnt[x])
            for (auto d : factors[x]) cnt[d] = 0;
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
不妨先考虑一个基础问题, 当 g === 1 时
此时我们就在求, 当前数组里有多少个数, 与 x 互质
这个就是取出 x 的全部质因子 ps, 容斥即可
每次修改时, 也是对质因子的组合的 cnt 进行修改
好, 那现在 g 不是 1, 该怎么办呢 ???
很简单, 在容斥的时候, 把上面用来访问 cnt 的数, 每个都 *g 即可
不过现在修改的时候, 就是得对全部的因子进行修改了 (因为要覆盖到全部的 g)
*/
