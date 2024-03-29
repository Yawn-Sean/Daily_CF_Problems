#include <bits/stdc++.h>
#define MAXN 2000
#define INF ((int) 1e9)
using namespace std;

int n, ans, A[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int one = 0;
    for (int i = 1; i <= n; i++) if (A[i] == 1) one++;
    if (one > 0) { printf("%d\n", n - one); return 0; }

    ans = INF;
    for (int i = 1; i <= n; i++) {
        int g = A[i];
        for (int j = i; j <= n; j++) {
            g = gcd(g, A[j]);
            if (g == 1) ans = min(ans, j - i + n - 1);
        }
    }
    if (ans < INF) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
