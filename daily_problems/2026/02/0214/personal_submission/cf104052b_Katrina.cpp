#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
vector<vector<int>> v = {{2, 1, 1, 0}, {2, 0, 2, 0}, {1, 1, 2, 1}};
void solve() {
    vector<int> a(4);
    for (int i = 0; i < 4; ++i) cin >> a[i];
    int ans = 2e9;
    for (int i = 0; i < (1 << 4); ++i) {
        int tot = 0, ned = 2e9;
        for (int j = 0; j < 4; ++j) {
            if (i >> j & 1) tot += a[j];
        }
        for (int j = 0; j < 3; ++j) {
            int t = 0;
            for (int k = 0; k < 4; ++k) {
                if (i >> k & 1) t += v[j][k];
            }
            ned = min(ned, t);
        }
        if (ned) ans = min(ans, tot / ned);
    }
    cout << ans << "\n";
}

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int T = 1;
    cin >> T;  
    while (T--) solve();    
    return 0;
} 
