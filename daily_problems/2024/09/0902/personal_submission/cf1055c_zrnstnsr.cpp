#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    ll g = gcd(ta, tb);
    ll da = ra - la, db = rb - lb;
    la %= ta; lb %= tb;
    lb += (la - lb) / g * g;
    ll ans;
    if (la <= lb) {
        ans = min(lb + db, la + da) - lb;
        lb -= g;
        ans = max(ans, min(lb + db, la + da) - la);
    } else {
        ans = min(lb + db, la + da) - la;
        lb += g;
        ans = max(ans, min(lb + db, la + da) - lb);
    }
    println("{}", max(ans + 1, 0LL));
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
