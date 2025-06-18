#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        i64 n, c;
        cin >> n >> c;
        vector<i64> a(n);
        for (i64 i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return (1ll * (i + 1) * c -  a[i]) < (1ll * (j + 1) * c - a[j]);
        });

        i64 sum = a[0];
        bool ok = true;
        for (auto& idx: order) {
            if (idx == 0) {
                continue;
            }
            sum += a[idx];

            if (sum < 1ll * (idx + 1) * c) {
                cout << "No\n";
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
        }
    }
    return 0;
}
