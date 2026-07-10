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
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<int> a = p;
    a.insert(a.end(), p.begin() + 1, p.end());
    for (int i = 1; i <= n * 2; ++i) a[i] += i;
    dbg(a | views::drop(1));
    int ans = n;
    vector<int> cnt(n * 3 + 5, 0);
    for (int i = 1; i <= n; ++i) {
        dbg(i, a[i], cnt[a[i]]);
        // ans += cnt[a[i]] << 1;
        ++cnt[a[i]];
    }
    for (int i = n + 1; i < n * 2; ++i) {
        dbg(i, a[i], cnt[a[i]]);
        --cnt[a[i - n]];
        ans += cnt[a[i]] << 1;
        ++cnt[a[i]];
    }
    cout << ans;
    return 0;
}

/*
a[a[x]] == x
要么是 a[x] == x, 每个数都会出现一次
要么是 a[x] == y && a[y] ==x
因为是循环, 所以只要 x,y 满足 dis(pos[x] -> pos[y]) == x-y 即可
这个怎么做呢? 把数组复制一份, 于是只要:
pos[y] - pos[x] == x - y
pos[x] + x == pos[y] + y
*/
