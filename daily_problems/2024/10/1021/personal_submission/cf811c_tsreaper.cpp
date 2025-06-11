#include <bits/stdc++.h>
#define MAXN 5000
#define INF ((int) 1e9)
using namespace std;

int n, A[MAXN + 10];

int L[MAXN + 10], R[MAXN + 10], f[MAXN + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (L[A[i]] == 0) L[A[i]] = i;
        R[A[i]] = i;
    }
    for (int i = 1; i <= n; i++) f[i] = -INF;
    for (int i = 0; i < n; i++) {
        int l = n + 1, r = 0, x = 0;
        f[i + 1] = max(f[i + 1], f[i]);
        for (int j = i + 1; j <= n; j++) {
            l = min(l, L[A[j]]);
            r = max(r, R[A[j]]);
            if (!vis[A[j]]) x ^= A[j];
            vis[A[j]] = true;
            if (l <= i) break;
            if (r > j) continue;
            f[j] = max(f[j], f[i] + x);
        }
        for (int j = i + 1; j <= n; j++) vis[A[j]] = false;
    }
    printf("%d\n", f[n]);
    return 0;
}
