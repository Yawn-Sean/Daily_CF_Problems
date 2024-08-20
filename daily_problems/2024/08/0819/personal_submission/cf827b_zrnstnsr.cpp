#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    int m = n - k - 1;
    cout << m / k * 2 + min(2, m % k) + 2 << '\n';
    for (int i = 1; i <= k; ++i) cout << "1 " << i + 1 << '\n';
    for (int i = 2; i + k <= n; ++i) cout << i << ' ' << i + k << '\n';
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
