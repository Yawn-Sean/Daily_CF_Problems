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
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "No";
        return 0;
    }
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> c;
    c.reserve(n * m);
    for (auto x : a)
        for (auto y : b)
            c.push_back(x * 2 - y);
    sort(all(c));
    const int tot = n * m;
    vector<int> ans;
    ans.reserve(m);
    for (int i = 0; i < tot;) {
        int j = i;
        while (j < tot && c[j] == c[i]) ++j;
        if (j - i == n) ans.push_back(c[i]);
        i = j;
    }
    ans.shrink_to_fit();
    vector<int> d;
    d.reserve(ans.size() * m);
    for (auto x : ans)
        for (auto y : a)
            d.push_back(y * 2 - x);
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    if (int(d.size()) != m)
        cout << "No";
    else {
        cout << "Yes\n"
             << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
    }
    return 0;
}
