#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

i64 p[11];

int main() {
    p[0] = 1ll;
    for (int i = 1; i <= 10; i++) {
        p[i] = p[i - 1] * 10ll;
    }

    int n, k;
    cin >> n >> k;

    vector<i64> a(n / k), b(n / k);
    for (int i = 0; i < n / k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n / k; i++) {
        cin >> b[i];
    }

    /* 每一块分开考虑 */
    i64 ans = 1ll;
    for (int i = 0; i < n / k; i++) {
        i64 lim = p[k] - 1;
        i64 bad_lo = p[k - 1] * b[i];
        i64 bad_hi = p[k - 1] * (b[i] + 1) - 1;
        // [0, bad_hi] - [0, bad_lo]
        i64 bad_cnt = (bad_hi / a[i] + 1) - (bad_lo / a[i] + 1);
        if (bad_lo % a[i] == 0) {
            bad_cnt++;
        }

        i64 tot_cnt = lim / a[i] + 1;
        // cout << (tot_cnt - bad_cnt) << ' ';
        ans = (ans * (tot_cnt - bad_cnt)) % mod;
    }
    // cout << '\n';
    cout << ans;

    return 0;
}
