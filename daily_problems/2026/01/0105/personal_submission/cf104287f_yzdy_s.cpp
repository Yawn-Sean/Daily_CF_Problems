#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a,b,c;cin >> a >> b >> c;
    int LCM = lcm(a, b);
    int res = LCM % c;
    // cout << res << endl;
    res = gcd(res, c);
    int ans = (c + res - 1) / res * res - res;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}