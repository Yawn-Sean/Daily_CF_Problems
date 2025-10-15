#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int pt = 0;
    int ans = 0;

    while (pt < n) {
        i64 mx = 0;
        while (pt < n && a[pt] <= 2ll * k) {
            mx = max(mx, (i64)a[pt]);
            pt++;
        }

        if (mx == 0) {
            while (a[pt] > 2ll * k) {
                k *= 2;
                ans++;
            }
            k = max(k, (i64)a[pt]);
            pt++;
        } else {
            k = max(k, mx);
        }
    }

    cout << ans << "\n";
    return 0;
}
