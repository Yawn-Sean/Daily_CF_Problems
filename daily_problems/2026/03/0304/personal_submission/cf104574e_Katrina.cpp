#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {  
    vector<int> a(53);
    for (int i = 1; i <= 52; ++i) cin >> a[i];
    vector<int> b(53);
    for (int j = 0; j < 8; ++j) {
        int p = 1, q = 27;
        for (int i = 1; i <= 52; ++i) {
            if (i & 1) {
                b[i] = a[p];
                p++;
            }
            else {
                b[i] = a[q];
                q++;
            }
        }
        // for (int i = 1; i <= 52; ++i) cout << b[i] << " \n"[i == 52];
        a = b;
        int cnt = 0;
        for (int i = 1; i <= 26; ++i) {
            if (a[i] == 1) cnt++;
        }
        if (cnt == 4) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
