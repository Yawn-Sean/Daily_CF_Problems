#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m, A[MAXN + 5];
long long ans;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int cl = 0, cr = 0;
    long long sl = 0, sr = 0;
    for (int i = 1; i <= n; i++) if ((n - i) % m == 0)
        cr++, sr += A[i];

    ans = 1e18;
    for (int i = 1; i <= n; i++) {
        long long x = 1LL * cl * A[i] - sl;
        long long y = sr - 1LL * cr * A[i];
        ans = min(ans, (x + y) * 2);
        if ((i - 1) % m == 0) cl++, sl += A[i];
        if ((n - i) % m == 0) cr--, sr -= A[i];
    }

    printf("%lld\n", ans);
    return 0;
}
