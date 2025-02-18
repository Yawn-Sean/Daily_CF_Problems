#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    __int128 sm = 0;
    long long k1 = 0, k2 = 1LL * (n - 1) * n / 2;
    for (int i = 1; i <= n; i++) k1 += abs(i - (n + 1) / 2);
    while (m--) {
        int x, y; scanf("%d%d", &x, &y);
        sm += x * n;
        if (y < 0) sm += k1 * y;
        else sm += k2 * y;
    }
    printf("%.12f\n", 1.0 / n * sm);
    return 0;
}
