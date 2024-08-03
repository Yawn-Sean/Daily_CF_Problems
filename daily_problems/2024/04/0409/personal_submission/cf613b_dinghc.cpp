#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 100001;
pair<long long, int> a[MXN];
long long sums[MXN];
long long ans[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, A, cf, cm;
    long long m;
    cin >> n >> A >> cf >> cm >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + a[i - 1].first;
    }

    if (static_cast<long long>(A) * n - sums[n] <= m) {
        cout << static_cast<long long>(n) * cf + static_cast<long long>(A) * cm << "\n";
        for (int i = 0; i < n; i++) {
            cout << A << " ";
        }
    } else {
        auto bisect = [&] (long long b, int m) -> long long {
            long long lo = a[0].first + 1, hi = A - 1;
            while (lo <= hi) {
                long long mid = (hi - lo) / 2 + lo;
                int j = lower_bound(a, a + m, pair<long long, int>{mid, 0}) - a;
                if (static_cast<long long>(mid) * j - (sums[j]) <= b) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return hi;
        };
    
        tuple<long long, long long, int> res {0LL, 0LL, 0};
        for (int i = n; i > 0; i--) {
            long long b = m - (static_cast<long long>(A) * (n - i) - (sums[n] - sums[i]));
            if (b < 0) break;
            long long mi = bisect(b, i);
            res = max(res, {mi * cm + (n - i) * cf, mi, i});
        }
        auto& [mx, mi, k] = res;
        for (int i = 0; i < n - k; i++) {
            a[n - i - 1].first = A;
        }
        int j = lower_bound(a, a + k, pair<long long, int>{mi, 0}) - a;
        for (int i = 0; i < j; i++) {
            a[i].first = mi;
        }
        for (int i = 0; i < n; i++) {
            auto&[val, idx] = a[i];
            ans[idx] = val;
        }
        cout << mx << "\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
    }

    return 0;
}

