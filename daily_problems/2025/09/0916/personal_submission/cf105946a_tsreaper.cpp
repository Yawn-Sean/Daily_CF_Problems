#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    unordered_map<long long, int> cnt;
    for (int i = 1; i <= n; i++) {
        long long x; scanf("%lld", &x);
        cnt[x]++;
    }

    long long ans = 0;
    for (auto &p : cnt) {
        for (int i = 1; i <= 4; i++) if (cnt.count(i) && cnt.count(i + p.first)) {
            if (i == p.first) ans += 1LL * cnt[i] * (cnt[i] - 1) * cnt[i + p.first];
            else {
                long long t = 1LL * cnt[i] * p.second * cnt[i + p.first];
                if (p.first > 4) t *= 2;
                ans += t;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
