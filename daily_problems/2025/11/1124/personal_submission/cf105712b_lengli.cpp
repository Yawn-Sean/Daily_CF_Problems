#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64> a(n);
        int64 S = 0;
        int nz = 0;
        int64 mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            S += a[i];
            if (a[i] > 0) ++nz;
            mx = max(mx, a[i]);
        }

        if (S == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (n == 2) {
            int64 x = a[0], y = a[1];
            int64 R = ( (x % 3) == (y % 3) ) ? 2 : 1;
            cout << (S - R) << '\n';
            continue;
        }

        bool anyPair = false;
        for (int i = 0; i < n; ++i) if (a[i] >= 2) { anyPair = true; break; }

        if (!anyPair) {
            cout << 0 << '\n';
            continue;
        }

        if (nz == 1 && S == 3) {
            cout << 1 << '\n'; 
            continue;
        }

        cout << (S - 1) << '\n';
    }

    return 0;
}
