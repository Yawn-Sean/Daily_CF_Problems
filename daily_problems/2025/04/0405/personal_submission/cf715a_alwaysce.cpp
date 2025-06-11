#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n;
    cin >> n;
    cout << 2 << '\n';
    for (int k = 2; k <= n; k++) {
        // k(k+1)
        // (k-1)k
        // (k(k+1))^2 - k(k-1) / k
        cout << 1ll * k * (k + 1) * (k + 1) - (k - 1) << '\n';
    }

    return 0;
}
