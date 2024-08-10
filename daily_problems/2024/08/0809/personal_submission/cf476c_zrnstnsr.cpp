#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int a, b;
    cin >> a >> b;
    ll left = (1LL * a * (a + 1) / 2 % mod * b + a) % mod, right = 1LL * b * (b - 1) / 2 % mod;
    cout << left * right % mod << endl;
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
