#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) if ((i * i + j * j) % m == 0) {
        long long x = n / m, y = x;
        if (i > 0 && i <= n % m) x++;
        if (j > 0 && j <= n % m) y++;
        ans += x * y;
    }
    printf("%lld\n", ans);
    return 0;
}
