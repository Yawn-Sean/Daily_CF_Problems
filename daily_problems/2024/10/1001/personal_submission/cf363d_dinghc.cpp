#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int b[N];
int p[N];

int main() {
    int n, m, a;
    scanf("%d%d%d", &n, &m, &a);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    sort(b, b + n);
    sort(p, p + m);
    auto calc_used_amt = [&] (int k) -> long long {
        long long tot = 0;
        // p[k - 1] <=> b[n - 1] ... p[0] <=> b[n - k]
        for (int i = 0; i < k; i++) {
            if (b[n - k + i] < p[i]) {
                tot += p[i] - b[n - k + i];
            }
        }
        return tot;
    };
    int lo = 0, hi = min(n, m);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (calc_used_amt(mid) <= a) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    long long tot_amt = 0;
    for (int i = 0; i < hi; i++) {
        tot_amt += p[i];
    }
    printf("%d %lld\n", hi, max(0LL, tot_amt - a));
    return 0;
}

