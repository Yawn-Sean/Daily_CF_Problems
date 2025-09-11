#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    int g = gcd(n, K);
    long long ans = 1LL * (n - g) * K + 1LL * (g - 1) * (K - 1);
    printf("%lld\n", ans);
    return 0;
}
