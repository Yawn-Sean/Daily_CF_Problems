#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;

    vector<i64> a(n), b(m);
    i64 tot_a = 0, tot_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot_a += a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        tot_b += b[i];
    }

    i64 bound = 2e5;
    vector<int> mp_a(2 * bound + 1), mp_b(2 *bound + 1);
    for (int i = 0; i < n; i++) {
        i64 tmp = tot_a - a[i];
        if (-bound <= tmp && tmp <= bound) {
            mp_a[tmp + bound]++;
        }
    }
    for (int j = 0; j < m; j++) {
        i64 tmp = tot_b - b[j];
        if (-bound <= tmp && tmp <= bound) {
            mp_b[tmp + bound]++;
        }
    }

    while (q--) {
        int x;
        cin >> x;
        bool ok = false;
        for (int i = 1; i * i <= abs(x); i++) {
            if (x % i == 0) {
                int j = x / i;
                if (mp_a[i + bound] > 0 && mp_b[j + bound] > 0) {
                    ok = true;
                    break;
                }
                if (mp_a[j + bound] > 0 && mp_b[i + bound] > 0) {
                    ok = true;
                    break;
                }
                if (mp_a[-i + bound] > 0 && mp_b[-j + bound] > 0) {
                    ok = true;
                    break;
                }
                if (mp_a[-j + bound] > 0 && mp_b[-i + bound] > 0) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
   
    return 0;
}
