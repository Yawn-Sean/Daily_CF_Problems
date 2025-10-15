#include <bits/stdc++.h>  
typedef long long ll;  
using namespace std;  

ll mod = 998244353;

void solve(){
    ll x, y, m;
    cin >> x >> y >> m;

    if(x >= m || y >= m){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    if(x <= 0 && y <= 0){
        cout << -1 << endl;
        return;
    }
    if (x < 0){
        ans += -x / y;
        if (ans * y != -x){
            ans += 1;
        }
        x += ans * y;

    }

    if (y < 0){
        ans += -y / x;
        if (ans * x != -y){
            ans += 1;
        }
        y += ans * x;
    }
    while (max(x, y) < m){
        ll p = min(x, y);
        ll q = max(x, y);
        p += q;
        x = p;
        y = q;
        ans ++ ;
    }
    cout << ans << endl;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    T = 1;
    while (T--){
        solve();
    }
    return 0;
}
