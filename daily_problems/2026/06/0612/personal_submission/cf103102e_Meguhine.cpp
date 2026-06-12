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

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    vector<vector<int>> ok(9);
    for (int i = 0; i < 9; ++i) {
        ok[i].reserve(9);
        const ai2 ci{i / 3, i % 3};
        for (int j = 0; j < 9; ++j) {
            const ai3 cj{j / 3, j % 3};
            ai3 c{ci[0] - cj[0], ci[1] - cj[1]};
            if (c[0] < 0) c[0] += 3;
            if (c[1] < 0) c[1] += 3;
            int x = c[0] * c[1] * 2 +
                    c[0] * (c[0] - 1) / 2 +
                    c[1] * (c[1] - 1) / 2;
            if (x % 3 == 0) ok[i].push_back(j);
        }
    }
    int n;
    cin >> n;
    LL ans = 0;
    ai9 mp{};
    mp[0] = 1;
    for (ai2 c{}; n--;) {
        int x;
        cin >> x;
        x %= 3;
        if (x != 0) {
            --x;
            if (++c[x] == 3) c[x] = 0;
        }
        const int y = c[0] * 3 + c[1];
        for (int z : ok[y]) ans += mp[z];
        ++mp[y];
    }
    cout << ans;
    return 0;
}
