#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, b1, b2;
    cin >> n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0 && gcd(i, n/i) == 1) {
            b1 = i, b2 = n / i;
            int s = (n - 1) * b1 * b2, c = s / n;
            for (int a1 = 1; a1 < b1; ++a1) {
                if ((c - a1 * b2) % b1 == 0) {
                    int a2 = (c - a1 * b2) / b1;
                    if (a2 >= 1 && a2 < b2) {
                        cout << "YES\n";
                        cout << "2\n";
                        cout << a1 << ' ' << b1 << '\n';
                        cout << a2 << ' ' << b2 << '\n';
                        return;
                    }
                }
            }
        }
    }
    cout << "NO";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}