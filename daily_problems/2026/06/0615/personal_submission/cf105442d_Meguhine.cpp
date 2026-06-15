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

using B = __int128;
LL isqrt(const B x) {
    B r = sqrt((long double)x);
    while (r * r <= x) ++r;
    while (r * r > x) --r;
    return r;
}

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    set<ai2> xmn, ymn;
    set<ai2, greater<>> xmx, ymx;
    auto check = [&]() -> bool {
        auto it = xmn.begin();
        return (*it)[0] == (*next(it))[0];
    };
    auto work = [&]() -> void {
        set<ai2> o{*xmn.begin(), *xmx.begin()};
        auto t = *ymn.begin();
        o.insert({t[1], t[0]});
        t = *ymx.begin();
        o.insert({t[1], t[0]});
        if (check()) {
            o.insert(*next(xmn.begin()));
            o.insert(*next(xmx.begin()));
            t = *next(ymn.begin());
            o.insert({t[1], t[0]});
            t = *next(ymx.begin());
            o.insert({t[1], t[0]});
        }
        assert(o.size() == 4);
        dbg(o);
        for (auto x : o) {
            xmn.erase(x);
            xmx.erase(x);
            ymn.erase({x[1], x[0]});
            ymx.erase({x[1], x[0]});
        }
    };
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xmn.insert({x, y});
        xmx.insert({x, y});
        ymn.insert({y, x});
        ymx.insert({y, x});
    }
    const int m = n / 4;
    for (int i = 1; i < m; ++i) {
        work();
    }
    dbg(xmn);
    assert(xmn.size() == 4);
    const vector<ai2> a{all(xmn)};
    set<LL> e;
    for (int i = 0; i < 3; ++i) {
        const auto [xi, yi] = a[i];
        for (int j = i + 1; j < 4; ++j) {
            const auto [xj, yj] = a[j];
            const int dx = xi - xj;
            const int dy = yi - yj;
            e.insert(1ll * dx * dx + 1ll * dy * dy);
        }
    }
    const LL p = *e.begin();
    const LL q = e.size() == 3 ? (*next(e.begin())) : (p);
    dbg(p, q, e);
    cout << isqrt(B(p) * q);
    return 0;
}
