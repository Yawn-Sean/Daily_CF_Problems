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
    int n;
    cin >> n;
    vector<LL> pos(n), a(n), b(n);
    for (auto &x : pos) cin >> x;
    for (auto &x : a) cin >> x;
    sort(all(a));
    auto check_and_execute = [&](const LL _x) -> void {
        LL x = (b[0] = _x);
        for (int i = 1; i < n; ++i) {
            b[i] = (x = (pos[i] - pos[i - 1]) - x);
        }
        sort(all(b));
        if (a == b) {
            x = _x;
            cout << x;
            for (int i = 1; i < n; ++i) {
                x = (pos[i] - pos[i - 1]) - x;
                cout << ' ' << x;
            }
            exit(0);
        }
    };
    array<vector<LL>, 2> rs{};
    rs[0].reserve(n); // means (y+x) is a radius for y in rs[0]
    rs[1].reserve(n); // means (y-x) is a radius for y in rs[1]
    rs[0].push_back(0);
    {
        LL x = 0;
        for (int i = 1; i < n; ++i) {
            x = (pos[i] - pos[i - 1]) - x;
            rs[i & 1].push_back(x);
        }
    }
    dbg(rs[0]);
    dbg(rs[1]);
    if (n & 1) {
        LL x = accumulate(all(a), 0ll) -
               accumulate(all(rs[0]), 0ll) -
               accumulate(all(rs[1]), 0ll);
        check_and_execute(x);
        __builtin_unreachable();
        return 0;
    }
    check_and_execute(a[0] - *min_element(all(rs[0])));
    check_and_execute(*min_element(all(rs[1])) - a[0]);
    __builtin_unreachable();
    return 0;
}

/*
不难发现, 如果 n 是奇数, 实际上这道题目就非常的简单
直接可以通过解方程确定第一个齿轮的半径, 有唯一解

如果 n 是偶数怎么办呢, 看**最小值**即可
*/
