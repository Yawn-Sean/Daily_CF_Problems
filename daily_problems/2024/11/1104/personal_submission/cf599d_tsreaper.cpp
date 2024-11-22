#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

long long P(int n) {
    return 1LL * n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    long long K; scanf("%lld", &K);
    vector<pll> vec;
    for (int n = 1; ; n++) {
        long long t = 2 * K + 1LL * n * n * n - 1LL * n * n - 2 * P(n - 1);
        if (t < 0) continue;
        long long v = 1LL * n * n + n;
        long long m = (t + v - 1) / v;
        if (m < n) break;
        if (t % v) continue;
        vec.push_back({n, m});
        if (n != m) vec.push_back({m, n});
    }
    sort(vec.begin(), vec.end());
    printf("%d\n", vec.size());
    for (pll p : vec) printf("%lld %lld\n", p.first, p.second);
    return 0;
}
