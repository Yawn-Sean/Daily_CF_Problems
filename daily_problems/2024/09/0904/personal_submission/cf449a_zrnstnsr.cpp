#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k >= n + m - 1) { println("-1"); return; }
    auto cal = [&](ll fs, ll sc) -> ll {
        if (k < fs) return fs / (k + 1) * sc;
        else return sc / (k - fs + 2);
    };
    println("{}", max(cal(n, m), cal(m, n)));
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
