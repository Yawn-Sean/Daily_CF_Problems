#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    if (x > y) swap(x, y);
    long long l = x / gcd(x, y) * y;
    long long a = l / x - 1;
    long long b = l / y;
    if ((a + b - 1) / b < z) printf("OBEY\n");
    else printf("REBEL\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
