#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int d = 0, st = -1;
    for (int i = n - 2; i >= 0; --i) {
        d = a[i + 1] - a[i];
        if (d <= 0) {
            cout << a[i] / (a[i + 1] - 1) << "\n";
            return;
        }
    }
    d = a[n - 1] - a[n - 2];
    cout << max(d, a[n - 1] / d) << "\n";
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
