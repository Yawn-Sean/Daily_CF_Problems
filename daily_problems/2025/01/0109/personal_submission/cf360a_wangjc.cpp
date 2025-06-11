#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n, INT_MIN);
    // for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> up(n, 1e9);
    vector<int> add(n);
    vector<vector<int>> record;
    while (m--) {
        int k, l, r, d;
        cin >> k >> l >> r >> d;
        l--;
        r--;
        if (k == 1) {
            for (int i = l; i <= r; i++) {
                add[i] += d;
            }
        } else {
            for (int i = l; i <= r; i++) {
                up[i] = min(up[i], d - add[i]);
            }
        }
        record.push_back({l, r, d, k});

    }
    for (int i = 0; i < n; i++) a[i] = up[i];
    for (int i = 0; i < record.size(); i++) {
        int l = record[i][0];
        int r = record[i][1];
        int d = record[i][2];
        int k = record[i][3];
        if (k == 1) {
            for (int i = l; i <= r; i++) {
                a[i] += d;
            }
        } else {
            int mx = INT_MIN;
            for (int i = l; i <= r; i++) {
                mx = max(mx, a[i]);
            }
            if (mx < d) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << up[i] << " ";
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
