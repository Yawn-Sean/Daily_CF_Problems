#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    i64 mod = 1e9 + 7;
    int q;
    cin >> q;
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        // f(x)=log2(x), l<=x<=r
        // g(x)=log(f(x))x
        i64 ans = 0;
        for (i64 b = 2; b <= 60; b++) {
            i64 left = 1ll << b;
            i64 right = 1ll << (b + 1);
            if (right <= l) continue;
            if (left > r) break;

            i64 L = max(left, l);
            i64 R = min(right, r + 1);

            i64 x = b; // log2(x)在[L, R)内恒为b
            
            // log_b(y), L<=y<R 的和
            i64 pt = 0;
            i64 lower = 1, upper = b;
            while (true) {            
                if (upper <= L) {
                    lower = min(lower, (r + 1) / b + 1) * b;
                    upper = min(upper, (r + 1) / b + 1) * b;
                    pt++;
                    continue;
                }
                if (lower >= R) break;

                i64 LL = max(lower, L);
                i64 RR = min(upper, R);
                i64 lens = max(0ll, RR - LL);
                ans = (ans + 1ll * lens % mod * pt % mod) % mod;
                pt++;
                
                lower = min(lower, (r + 1) / b + 1) * b;
                upper = min(upper, (r + 1) / b + 1) * b;
            }
        }
        cout << ans % mod << '\n';
    }
    return 0;
}
