#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; scanf("%lld", &n);

    set<long long> ans;
    for (int p = 1; p <= 2; p++) {
        long long m = (n - 1) * p;
        for (int i = 1; 1LL * i * i * i <= m; i++) if (m % i == 0) {
            if (i - 1 > 0 && (i - 1) % 2 == p % 2) {
                long long t = 1LL * i * (i + 1);
                if (m % t == 0) ans.insert(i - 1);
            }
            if (i - 2 > 0 && (i - 2) % 2 == p % 2) {
                long long t = 1LL * i * (i - 1);
                if (m % t == 0) ans.insert(i - 2);
            }

            long long head = 1, tail = sqrt(m / i) + 3;
            while (head < tail) {
                long long mid = (head + tail) >> 1;
                if ((mid + 1) * (mid + 2) >= m / i) tail = mid;
                else head = mid + 1;
            }
            if ((head + 1) * (head + 2) == m / i && head % 2 == p % 2) ans.insert(head);
        }
    }

    printf("%d\n", ans.size());
    for (long long x : ans) printf("%lld ", x);
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
