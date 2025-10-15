#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto b = a;
    int l = 0, r = 0;
    int ans = 0;
    int cur = k;
    while (l <= r && r < n) {
        if (a[r] == 0) {
            b[r] = 1;
            cur--;
        }
        while (l <= r && cur < 0) {
            if (a[l] == 0) {
                b[l] = 0;
                l++;
                cur++;
            } else l++;
        }
        if (r - l + 1 > ans) {
            ans = r - l + 1;
        }
        r++;
    }
    cout << ans << endl;
    b = a;
    cur = k, l = 0, r = 0;
    while (l <= r && r < n) {
        if (a[r] == 0) {
            b[r] = 1;
            cur--;
        }
        while (l <= r && cur < 0) {
            if (a[l] == 0) {
                b[l] = 0;
                l++;
                cur++;
            } else l++;
        }
        if (r - l + 1 == ans) {
            for (auto i : b) {
                cout << i << " ";
            }
            return;
        }
        r++;
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
