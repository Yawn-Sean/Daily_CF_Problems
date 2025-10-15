#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve(){
    ll a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    auto f = [&] (int x, int y) -> ll {
        int res = x / y;
        if (y * res > x) res--;
        return res;
    };
    ll ans = max(abs(f(x1 + y1, 2 * a) - f(x2 + y2, 2 * a)), abs(f(x1 - y1, 2 * b) - f(x2 - y2, 2 * b)));
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
