/*
    以0.5为单位的二分，没写过，还是有所收获的。。。。
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-7;
void solve(){
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<double> ans;
    sort(a.begin(), a.end());
    double res = 0;
    int l = 0, r = 2e9;
    vector<double> x;
    int f = 1;
    while (l <= r && f) {
        ans.clear();
        double mid = ((double) l + (double) r) / 2;
        // cerr << l << " " << r << " " << mid << "\n";
        int cnt = 0;
        double cur = 0;
        for (int p = 0; p < n; p++) {
            if (a[p] - cur > eps) {
                cur = a[p] + 2 * mid;
                ans.push_back(a[p] + mid);
                cnt++;
            }
        }
        if (l == r) f = 0;
        if (cnt > 3) {
            l = floor(mid + 0.5);
        } else {
            res = mid;
            x = ans;
            r = ceil(mid - 0.5);
        }
    }
    cout << fixed << setprecision(6) << res << "\n";
    while (x.size() < 3) {
        x.push_back(1.0);
    } 
    for (auto i : x) {
        cout << i << " ";
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

