#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int l = 0, r = 0;
    int ans = INT_MAX;
    int res = 0;
    for (auto i : b) res += i > 0;
    vector<int> cnt(m + 1);
    int tot = 0;
    while (l <= r && r < n) {
        cnt[a[r]]++;
        if (cnt[a[r]] == b[a[r] - 1]) res--;
        if (cnt[a[r]] > b[a[r] - 1]) tot++;
        while (res == 0) {
            ans = min(ans, tot);
            cnt[a[l]]--;
            if (cnt[a[l]] >= b[a[l] - 1]) tot--;
            if (cnt[a[l]] == b[a[l] - 1] - 1) res++;
            l++;
        }
        r++;
    }
    if (ans == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << ans  << endl;
    }
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
