#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;
typedef long long ll;

int n, A[MAXN + 10];
ll ans;

ll f[MAXN + 10][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) A[i] = abs(A[i] - A[i + 1]);
    n--;

    f[1][0] = A[1]; f[1][1] = -INF;
    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][1] + A[i], 1LL * A[i]);
        f[i][1] = f[i - 1][0] - A[i];
    }

    ans = -INF;
    for (int i = 1; i <= n; i++) ans = max({ans, f[i][0], f[i][1]});
    printf("%lld\n", ans);
    return 0;
}
