#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

int n, K, ans, A[MAXN + 10];

int nxt[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    nxt[n + 1] = n + 1;
    for (int i = n; i > 0; i--) {
        nxt[i] = nxt[i + 1];
        if (A[i] > 1) nxt[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        __int128 P = 1, S = 0;
        for (int j = nxt[i], last = i - 1; ; j = nxt[j + 1]) {
            __int128 t = P - S * K;
            if (t % K == 0) {
                t /= K;
                if (t >= 0 && t <= j - last - 1) ans++;
            }
            if (j > n) break;
            P *= A[j];
            S += A[j] + j - last - 1;
            last = j;
            if (P > INF) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
