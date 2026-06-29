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
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<unsigned char> tag(n + 1), ans(n + 1);
    queue<int> p;
    for (int i = 1; i <= n; ++i) {
        assert(tag[i] != 7);
        if (ans[i]) continue;
        if (!(tag[i] & 1))
            ans[i] = 1;
        else if (!(tag[i] & 2))
            ans[i] = 2;
        else
            ans[i] = 4;
        p.push(i);
        while (p.size()) {
            const int u = p.front();
            p.pop();
            for (auto v : e[u]) {
                tag[v] |= ans[u];
                assert(tag[v] != 7);
                if (popcount(tag[v]) == 2 && !ans[v]) {
                    ans[v] = tag[v] ^ 7;
                    p.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        // assert(popcount(ans[i]) == 1);
        if (ans[i] == 1)
            cout << 'a';
        else if (ans[i] == 2)
            cout << 'b';
        else {
            assert(ans[i] == 4);
            cout << 'c';
        }
    }
    return 0;
}
