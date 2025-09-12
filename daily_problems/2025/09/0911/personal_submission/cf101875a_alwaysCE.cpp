#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n, k;
    cin >> n >> k;

    // i64 full = n / k;
    // i64 left = n % k;
    // i64 ans = 1ll * k * (k - 1) / 2;

    i64 ans = 0, g = n, cur = k;
    while (g > 1 && cur > 0) {
      i64 d = (cur % g == 0 ? cur - 1 : cur);
      if (d <= 0) {
        break;
      }
      i64 g2 = gcd(g, d);
      ans += (g - g2) * d;
      g = g2;
      cur = d - 1;
    }
    cout << ans << endl;
    return 0;
}
