#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int m, R;
    cin >> m >> R;

    long double R2 = sqrtl(2) * R;
    long double ans = 0;

    ans += (R * 2) * m;
    ans += (R * 2 + R2) * (2 * (m - 1));
    // x > 1
    for (int x = 2; x <= m - 1; x++) {
        ans += (long double)2.0 * (m - x) * (R * (x - 1) + R2) * 2; 
    }

    cout << fixed << setprecision(15) << ans / m / m; 
    return 0;
}
