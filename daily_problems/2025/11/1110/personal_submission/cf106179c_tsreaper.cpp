#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long c; scanf("%lld", &c);
    printf("%lld %lld\n", c, c << (__lg(c) + 1));
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
