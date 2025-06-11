#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n;
    cin >> n;
    vector<ll> d;
    ll f1 = 1, f2 = 1, f3 = 2;
    int ans = 1;
    while (f3 <= n) {
        f2 = f1;
        f1 = f3;
        f3 = f1 + f2;
        ++ans;
    }
    println("{}", ans - 1);
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
