#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int a, b, m;
    cin >> a >> b >> m;
    bool fail = true;
    for (int i = 1; i < m && i <= a; ++i) {
        int d = i * 1000000000LL % m;
        d = (m - d) % m;
        if (b < d) {
            println("1 {:09}", i);
            fail = false;
            break;
        }
    }
    if (fail) println("2");
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
