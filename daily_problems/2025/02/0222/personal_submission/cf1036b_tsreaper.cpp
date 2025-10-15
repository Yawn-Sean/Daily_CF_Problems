#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, K; scanf("%lld%lld%lld", &n, &m, &K);
    if (K < max(n, m)) printf("-1\n");
    else printf("%lld\n", K - (n % 2 != K % 2 ? 1 : 0) - (m % 2 != K % 2 ? 1 : 0));
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
