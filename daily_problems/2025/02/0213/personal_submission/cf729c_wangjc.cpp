#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<vector<int>> car(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> car[i][0] >> car[i][1];
    }
    vector<int> p(k);
    for (int i = 0; i < k; i++) cin >> p[i];
    k++; p.push_back(s);
    sort(p.begin(), p.end());
    int ans = INT_MAX;
    int l = 1, r = INT_MAX;
    while (l <= r) {
        int x = l + r >> 1;
        int cur = 0, pos = 0, tot = 0;
        bool f = 1;
        while (pos < k) {
            int dif = p[pos] - cur;
            if (dif > x) {
                f = 0;
                break;
            } else {
                tot += max(dif * 3 - x, dif);
                cur = p[pos];
                pos++;
            }
        }
        if (tot > t) f = 0;
        if (f) {
            ans = x;
            r = x - 1;
        } else {
            l = x + 1;
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (car[i][1] >= ans) {
            res = min(res, car[i][0]);
        }
    }
    if (res == INT_MAX) {
        cout << "-1\n";
        return;
    } else {
        cout << res << "\n";
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
