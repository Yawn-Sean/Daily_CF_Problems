#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 100005;
long long a[MXN];
long long sums[MXN];
long long ans[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, greater<>());

    memset(ans, -1, sizeof(ans));

    ans[1] = 0LL;
    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + a[i - 1];
        ans[1] += a[i - 1] * (i - 1);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        k = min(k, n - 1);
        if (k == 1) {
            cout << ans[1] << " ";
        } else {
            if (ans[k] != -1) {
                cout << ans[k] << " ";
            } else {
                ans[k] = 0LL;
                long long sz = k;
                for (long long j = 1, t = 1; j < n; j += sz, sz *= k, t++) {
                    ans[k] += (sums[min(static_cast<long long>(n), j + sz)] - sums[j]) * t;
                }
                cout << ans[k] << " ";
            }
        }
    }

    return 0;
}

