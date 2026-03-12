#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


#define int long long
void solve() {  
    int n; ll s; cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    auto check = [&] (int x) -> bool {
        int cnt = x; ll res = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > cnt) {
                cnt--;
                res += a[i];
            }
        }
        res += cnt * (cnt + 1) / 2;
        // cout << res;
        return res < s;
    };

    int l = n, r = 2e9, ans = n - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans + 1 << "\n";
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
}
