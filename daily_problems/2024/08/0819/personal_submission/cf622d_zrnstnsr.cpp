#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i += 2) cout << i << ' ';
    if (n % 2) cout << n << ' ';
    for (int i = n - n % 2 - 1; i >= 1; i -= 2) cout << i << ' ';
    for (int i = 2; i < n; i += 2) cout << i << ' ';
    if (n % 2 == 0) cout << n << ' ';
    for (int i = n + n % 2 - 2; i >= 2; i -= 2) cout << i << ' ';
    cout << n << ' ';
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
