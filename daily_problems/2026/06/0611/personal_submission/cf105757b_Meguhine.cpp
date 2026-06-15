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

constexpr int N = 2e6 + 5;
bitset<N> notP;
int mn_p[N];
vector<int> prime;
void init_prime(const int n = N) { // init [1,n-1]
    mn_p[1] = notP[1] = 1;
    for (int i = 2; i < n; i++) {
        if (!notP[i]) prime.push_back(mn_p[i] = i);
        for (const int p : prime) {
            if (i > (n - 1) / p) break;
            notP[i * p] = 1, mn_p[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ai2> a;
    auto dfs = [&](auto &&self, int l, int r) -> bool {
        if (!notP[l + r]) {
            a.push_back({l, r});
            return 1;
        }
        for (int x = l + 2; x < r; x += 2) {
            if (!notP[x + r] && self(self, l, x - 1)) {
                a.push_back({x, r});
                return 1;
            }
        }
        return 0;
    };
    assert(dfs(dfs, (n & 1) + 1, n));
    vector<int> ans(n);
    if (n & 1) ans[n / 2] = 1;
    int p = 0, q = n - 1;
    for (auto [l, r] : a) {
        while (l <= r) {
            ans[p++] = l++;
            ans[q--] = r--;
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    init_prime();
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
