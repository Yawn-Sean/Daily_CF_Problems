#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
using namespace std;

int n, m, A[MAXN + 10][MAXM + 10];
bool ansR[MAXN + 10], ansC[MAXM + 10];

int r[MAXN + 10], c[MAXM + 10];

bool gao() {
    for (int i = 1; i <= n; i++) if (r[i] < 0) {
        ansR[i] = !ansR[i];
        r[i] *= -1;
        for (int j = 1; j <= m; j++) c[j] -= 2 * A[i][j], A[i][j] *= -1;
        return true;
    }

    for (int j = 1; j <= m; j++) if (c[j] < 0) {
        ansC[j] = !ansC[j];
        c[j] *= -1;
        for (int i = 1; i <= n; i++) r[i] -= 2 * A[i][j], A[i][j] *= -1;
        return true;
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        scanf("%d", &A[i][j]);
        r[i] += A[i][j];
        c[j] += A[i][j];
    }
    while (gao());

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (ansR[i]) cnt++;
    printf("%d", cnt);
    for (int i = 1; i <= n; i++) if (ansR[i]) printf(" %d", i);
    printf("\n");

    cnt = 0;
    for (int j = 1; j <= m; j++) if (ansC[j]) cnt++;
    printf("%d", cnt);
    for (int j = 1; j <= m; j++) if (ansC[j]) printf(" %d", j);
    printf("\n");

    return 0;
}
