#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll sx, sy, tx, ty, k;
    cin >> sx >> sy >> tx >> ty >> k;
    ll x = abs(sx - tx), y = abs(sy - ty);
    ll ans = x + y, mn = min(x, y), mx = max(x, y);
    mx -= (mn + 1) * k;
    if(mx > 0){
        ans += (mx + k - 1) / k + ((mx + k - 1) / k) % 2;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}