#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m, A[MAXN + 5], ans[MAXN + 5];

int B[MAXN + 5];
bool vis[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &A[i]), A[i]--;
    for (int i = 1; i < m; i++) {
        B[i] = (A[i + 1] - A[i] + n) % n;
        if (B[i] == 0) B[i] = n;
    }
    for (int i = 1; i < m; i++) {
        if (ans[A[i]] > 0) {
            if (ans[A[i]] != B[i]) { printf("-1\n"); return 0; }
        } else {
            if (vis[B[i]]) { printf("-1\n"); return 0; }
            vis[B[i]] = true;
            ans[A[i]] = B[i];
        }
    }
    for (int i = 0, j = 1; i < n; i++) {
        while (vis[j]) j++;
        if (ans[i] == 0) ans[i] = j++;
    }
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
