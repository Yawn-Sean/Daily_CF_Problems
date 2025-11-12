#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;
    vector<string> mp(n + 5);
    for (int i = 1; i <= n; i++) cin >> mp[i], mp[i] = "#" + mp[i];
    vector<int> one(n + 5);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[j][i] == '1') one[i]++, ans = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cnt = 0;
            int mx = 0;
            for (int k = 1; k <= n; k++) {
                if (mp[i][k] == '1' && mp[j][k] == '1') {
                    cnt++;
                    mx = max(mx, one[k]);
                }
            }
            ans = max(ans, min(mx, cnt));
        }
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}