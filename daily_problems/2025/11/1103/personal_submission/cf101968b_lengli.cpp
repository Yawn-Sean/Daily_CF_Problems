#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        int m = 2 * n;
        vector<long long> xs(m), ys(m);
        for (int i = 0; i < m; ++i) {
            cin >> xs[i] >> ys[i];
        }
        
        vector<long long> vxs = xs;
        vector<long long> vys = ys;
        sort(vxs.begin(), vxs.end());
        sort(vys.begin(), vys.end());

        if (vxs[n] == vxs[n - 1] || vys[n] == vys[n - 1]) {
            cout << 0 << '\n';
            continue;
        }
        
        ll v1 = 0, v2 = 0;
        ll ans = 1;
        long long xcut = vxs[n];
        long long ycut = vys[n];
        
        for (int i = 0; i < m; ++i) {
            if (xs[i] < xcut) {
                if (ys[i] < ycut) {
                    ++v1;
                    ans = (ans * v1) % MOD;
                } else {
                    ++v2;
                    ans = (ans * v2) % MOD;
                }
            }
        }
        
        cout << ans % MOD << '\n';
    }
    return 0;
}
