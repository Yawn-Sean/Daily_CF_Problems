#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> xs(n), ys(n), zs(n);
        for (int i = 0; i < n; i++) {
            cin >> xs[i] >> ys[i] >> zs[i];
        }
        vector<int> st_range(n);
        iota(st_range.begin(), st_range.end(), 0);
        sort(st_range.begin(), st_range.end(), [&](int a, int b) {
            return zs[a] < zs[b];
        });

        vector<long long> dp_pref(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int vi = st_range[i];
                int vj = st_range[j];

                if (xs[vi] == xs[vj]) {
                    if (ys[vi] == ys[vj]) {
                        dp_pref[vi] = max(dp_pref[vi], dp_pref[vj] + 1);
                    }
                } else {
                    long long a = xs[vi] - xs[vj];
                    long long b = ys[vi] - ys[vj];
                    long long c = zs[vi] - zs[vj];

                    if (b * b < 4LL * a * c) {
                        dp_pref[vi] = max(dp_pref[vi], dp_pref[vj] + 1);
                    }
                }
            }
        }

        vector<long long> dp_suff(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int vi = st_range[i];
                int vj = st_range[j];

                if (xs[vi] == xs[vj]) {
                    if (ys[vi] == ys[vj]) {
                        dp_suff[vi] = max(dp_suff[vi], dp_suff[vj] + 1);
                    }
                } else {
                    long long a = xs[vi] - xs[vj];
                    long long b = ys[vi] - ys[vj];
                    long long c = zs[vi] - zs[vj];

                    if (b * b < 4LL * a * c) {
                        dp_suff[vi] = max(dp_suff[vi], dp_suff[vj] + 1);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dp_pref[i] + dp_suff[i] - 1;
            if (i + 1 < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
