#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    if (!(cin >> tests)) return 0;
    const long double PI = acosl(-1.0L);
    
    cout.setf(std::ios::fixed);
    cout << setprecision(10);
    
    while (tests--) {
        ll m, T;
        cin >> m >> T;
        
        if (T <= 3 * m) {
            cout << 0 << '\n';
            continue;
        }
        
        ll l = 3;
        ll r = T / m; 
        auto f = [&](ll x) -> long double {
            long double side = ( (long double)T / (long double)x - (long double)m ) / 2.0L;
            if (side <= 0) return 0.0L;
            long double denom = tanl(PI / (long double)x);
            if (fabsl(denom) < 1e-18L) return 0.0L; 
            return side * side / denom * (long double)x;
        };
        
        while (l < r) {
            ll mid = (l + r) / 2;
            if (f(mid) < f(mid + 1)) l = mid + 1;
            else r = mid;
        }
        
        long double ans = f(l);
        cout << ans << '\n';
    }
    
    return 0;
}
