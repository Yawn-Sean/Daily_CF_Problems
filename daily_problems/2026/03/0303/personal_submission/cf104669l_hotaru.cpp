#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define endl '\n'
#define rep(i,a,b) for(int i = a ; i <= b ; i++)
#define per(i,a,b) for(int i = a ; i >= b ; i--)
#define int long long
using namespace std;
void solve() {
    int a,b;
    cin >> a >> b;
    int sum = (2 * a + b - 1) * b / 2;
    set<int> s;
    rep(i,1,sqrt(sum)) {
        if (sum % i == 0) {
            s.insert(sum/i);
            s.insert(i);
        }
    }
    int l = 0 ,r = 0;
    int ans = 1;
    rep(i,a,a + b - 2) {
        l += i;
        r += (2 * a + b - 1 - i);
        for (auto& v : s) {
            int minv = l / v;
            if (minv * v == l || (minv + 1) * v <= r) {
                ans = max(ans,v);
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    IOS;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}