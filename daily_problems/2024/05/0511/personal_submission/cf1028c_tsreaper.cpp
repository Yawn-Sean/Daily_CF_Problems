#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, L[MAXN + 10], D[MAXN + 10], R[MAXN + 10], U[MAXN + 10];

int fl[MAXN + 10], fd[MAXN + 10], fr[MAXN + 10], fu[MAXN + 10];
int gl[MAXN + 10], gd[MAXN + 10], gr[MAXN + 10], gu[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d%d", &L[i], &D[i], &R[i], &U[i]);

    fl[0] = -1e9; fd[0] = -1e9; fr[0] = 1e9; fu[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        fl[i] = max(fl[i - 1], L[i]);
        fd[i] = max(fd[i - 1], D[i]);
        fr[i] = min(fr[i - 1], R[i]);
        fu[i] = min(fu[i - 1], U[i]);
    }

    gl[n + 1] = -1e9; gd[n + 1] = -1e9; gr[n + 1] = 1e9; gu[n + 1] = 1e9;
    for (int i = n; i > 0; i--) {
        gl[i] = max(gl[i + 1], L[i]);
        gd[i] = max(gd[i + 1], D[i]);
        gr[i] = min(gr[i + 1], R[i]);
        gu[i] = min(gu[i + 1], U[i]);
    }

    for (int i = 1; i <= n; i++) {
        int l = max(fl[i - 1], gl[i + 1]);
        int d = max(fd[i - 1], gd[i + 1]);
        int r = min(fr[i - 1], gr[i + 1]);
        int u = min(fu[i - 1], gu[i + 1]);
        if (l <= r && d <= u) { printf("%d %d\n", l, d); break; }
    }

    return 0;
}
