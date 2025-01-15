#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n + 1));
    auto pos = a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
    int ans = 0;
    int l = 0, r = 0;
    while (l < n) {
        r = l;
        while (r + 1 < n) {
            bool ok = 1;
            for (int i = 1; i < m; i++) {
                if (pos[i][a[0][r + 1]] - pos[i][a[0][r]] != 1) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
            r++;
        }
        ans += (r - l + 1) * (r - l + 2) / 2;
        l = r + 1;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
