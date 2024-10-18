#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    if (!n) { cout << "0\n"; return; }
    map<ll, ll> len;
    len[0] = len[1] = 1;
    auto f = [&](auto &&self, ll x) -> ll {
        if (len.count(x)) return len[x];
        return len[x] = self(self, x / 2) * 2 + 1;
    };
    auto cnt = [&](auto &&self, ll x, ll pos) -> ll {
        if (pos <= 1) return pos;
        while (len[x/2] >= pos) x >>= 1;
        return x / 2 + x % 2 + self(self, x / 2, pos - len[x/2] - 1);
    };
    f(f, n);
    cout << (cnt(cnt, n, r) - cnt(cnt, n, l-1)) << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
