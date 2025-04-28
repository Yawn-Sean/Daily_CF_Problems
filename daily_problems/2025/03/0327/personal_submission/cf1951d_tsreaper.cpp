#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, K; scanf("%lld%lld", &n, &K);
    if (K == n) printf("YES\n1\n1\n");
    else if (K == 1) printf("YES\n1\n%lld\n", n);
    else if (K <= (n + 1) / 2) printf("YES\n2\n%lld 1\n", n - (K - 1));
    else printf("NO\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
