#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);
    unordered_map<int, unordered_map<int, int>> mp;
    long long ans = 0;
    while (n--) {
        int xa, ya, xb, yb; scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        int dx = xb - xa, dy = yb - ya;
        int g = gcd(abs(dx), abs(dy));
        dx /= g; dy /= g;
        ans += mp[-dx][-dy];
        mp[dx][dy]++;
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
