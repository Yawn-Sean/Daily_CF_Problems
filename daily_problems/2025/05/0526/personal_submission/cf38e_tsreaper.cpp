#include <bits/stdc++.h>
#define MAXN 3000
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n;
pii A[MAXN + 5];

long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].first, &A[i].second);
    
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) g[i] = g[i - 1] + A[i].first;

    f[1] = A[1].second;
    for (int i = 2; i <= n + 1; i++) {
        f[i] = INF;
        for (int j = 1; j < i; j++) {
            long long d = (g[i - 1] - g[j]) - 1LL * (i - j - 1) * A[j].first;
            f[i] = min(f[i], f[j] + d + A[i].second);
        }
    }
    printf("%lld\n", f[n + 1]);
    return 0;
}
