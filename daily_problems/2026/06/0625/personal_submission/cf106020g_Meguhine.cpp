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

constexpr int N = (1 << 20);
bitset<N> notP;
int mn_p[N];
vector<int> prime;
bool __init_sieve = []() -> bool { // init [1, N)
    mn_p[1] = notP[0] = notP[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!notP[i]) {
            prime.push_back(mn_p[i] = i);
        }
        for (const int p : prime) {
            if (i > (N - 1) / p) break;
            notP[i * p] = 1, mn_p[i * p] = p;
            if (i % p == 0) break;
        }
    }
    return 1;
}();

void solve() {
    int n, base;
    cin >> n;
    map<vector<int>, int> dp, nw;
    auto fuck = [&](const auto &a) -> void {
        const int m = int(a.size());
        const int S = 1 << a.size();
        for (int s = 1; s < S; ++s) {
            vector<int> o;
            int res = base;
            for (int i = 0; i < m; ++i)
                if (s >> i & 1) {
                    o.push_back(a[i]);
                    res += a[i];
                }
            bool ok = 1;
            for (int i = 1; i < int(o.size()) && ok; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (notP[o[i] ^ o[j]]) {
                        ok = 0;
                        break;
                    }
                }
            }
            dbg("\t", o, ok);
            if (ok) {
                auto it = nw.find(o);
                if (it == nw.end() || it->second < res) {
                    nw[o] = res;
                }
            }
        }
    };
    { // 第一个元素
        int x;
        cin >> x;
        dp[{x}] = x;
    }
    for (int x, t = 1; t < n; ++t) {
        cin >> x;
        clr(nw);
        for (auto it = dp.begin(); it != dp.end(); ++it) {
            auto a = it->first;
            a.push_back(x);
            sort(all(a));
            base = it->second;
            fuck(a);
        }
        swap(dp, nw);
        dbg(dp);
    }
    cout << *ranges::max_element(dp | views::values) << '\n';
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
