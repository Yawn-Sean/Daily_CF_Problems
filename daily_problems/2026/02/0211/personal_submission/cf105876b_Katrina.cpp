#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x;
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    iota(a.begin() + 1, a.end(), 1);
    for (int i = 1; i < n; ++i) {
        x ^= a[i];
        if (!x) {
            x ^= a[i];
            swap(a[i], a[i + 1]);
            x ^= a[i];
        }
    }
    x ^= a[n];
    if (!x) cout << "-1\n";
    else for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
} 
