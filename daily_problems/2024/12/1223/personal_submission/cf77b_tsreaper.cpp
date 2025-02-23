#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; scanf("%d%d", &a, &b);
    if (a == 0) {
        if (b == 0) printf("1\n");
        else printf("0.5\n");
        return;
    } else if (b == 0) {
        printf("1\n");
        return;
    }

    long long tot = 2LL * a * b;
    double v;
    if (b * 4 >= a) v = 1LL * a * b + 0.5 * a * a / 4;
    else v = tot - 0.5 * b * b * 4;
    printf("%.12f\n", v / tot);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
