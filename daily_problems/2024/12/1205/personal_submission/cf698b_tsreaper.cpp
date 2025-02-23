#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, ans, A[MAXN + 5];

int R, vis[MAXN + 5];

void dfs(int sn, int v) {
    vis[sn] = v;
    if (vis[A[sn]]) {
        if (vis[A[sn]] == v) {
            if (R) {
                if (A[sn] != R) ans++, A[sn] = R;
            } else {
                R = sn;
                ans++; A[sn] = R;
            }
        }
    } else {
        dfs(A[sn], v);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (i == A[i]) R = i;
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, i);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
