#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, long long> pil;

int n, A[MAXN + 10];
long long ans;

pil f[MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) {
        f[i].first = max(A[i], f[i - 1].first + 1);
        f[i].second = f[i - 1].second + f[i].first - A[i];
    }
    for (int i = n; i > 0; i--) {
        g[i].first = max(A[i], g[i + 1].first + 1);
        g[i].second = g[i + 1].second + g[i].first - A[i];
    }

    ans = 1e18;
    for (int i = 1; i <= n; i++) {
        int t = max({f[i - 1].first + 1, g[i + 1].first + 1, A[i]});
        ans = min(ans, f[i - 1].second + g[i + 1].second + t - A[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
