#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    // 1 + 2 + ... + x = (1 + x) * x / 2 = k
    // 1/2 * x^2 + 1/2 * x - k = 0
    if (1LL * (n - 1) * n / 2 < k) {
        cout << "Impossible\n";
    } else {
        int x = static_cast<int>(sqrt(0.25 + 2 * k) - 0.5);
        int r = k - 1LL * (1 + x) * x / 2;
        string ans = "(";
        for (int i = 1; i <= x; i++) {
            ans += "(";
        }
        for (int i = x; i >= 1; i--) {
            ans += ")";
            if (r == i) ans += "()";
        }
        ans += ")";
        int m = n - ans.length() / 2;
        for (int i = 0; i < m; i++) {
            ans += "()";
        }
        cout << ans << "\n";
    }
    return 0;
}
