#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);

    vector<int> fac;
    for (int i = 1; i * i <= n; i++) if (n % i == 0) {
        fac.push_back(i);
        if (i * i != n) fac.push_back(n / i);
    }
    sort(fac.begin(), fac.end());

    long long ans = 1LL * n * (n - 1);
    for (int x : fac) if (x > 1) {
        int head = 0, tail = fac.size() - 1;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (1LL * x * fac[mid] > n) tail = mid;
            else head = mid + 1;
        }
        ans = min(ans, 1LL * x * fac[head] - n);
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
