#include <bits/stdc++.h>
using namespace std;
typedef long double db;

void solve() {
    int m, t; scanf("%d%d", &m, &t);
    db ans = 0;
    for (int n = 3; 1LL * n * m <= t && n <= 1000; n++) {
        db s = (db) (t - n * m) / n;
        db PI = acos((db) -1);
        db area = 0.25 * n * s * s / tan(PI / n);
        ans = max(ans, area);
    }
    printf("%.12Lf\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}