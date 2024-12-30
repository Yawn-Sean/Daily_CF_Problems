#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        ans += 1LL * y * n - x;
        A[i] = x - y;
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) ans += 1LL * (n + 1 - i) * A[i];
    printf("%lld\n", ans);
    return 0;
}
