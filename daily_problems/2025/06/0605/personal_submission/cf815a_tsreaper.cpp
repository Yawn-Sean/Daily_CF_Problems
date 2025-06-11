#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m, A[MAXN + 5][MAXN + 5];
int ans, ansR[MAXN + 5], ansC[MAXN + 5];

int R[MAXN + 5], C[MAXN + 5];

int check(int X) {
    R[1] = X;
    for (int j = 1; j <= m; j++) C[j] = A[1][j] - X;
    for (int i = 2; i <= n; i++) {
        int a = -1;
        for (int j = 1; j <= m; j++) {
            int b = A[i][j] - C[j];
            if (b < 0) return -1;
            if (a == -1 || a == b) a = b;
            else return -1;
        }
        R[i] = a;
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) ret += R[i];
    for (int i = 1; i <= m; i++) ret += C[i];
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);

    int mn = A[1][1];
    for (int j = 1; j <= m; j++) mn = min(mn, A[1][j]);

    ans = -1;
    for (int i = 0; i <= mn; i++) {
        int t = check(i);
        if (t < 0) continue;
        if (ans == -1 || t < ans) {
            ans = t;
            for (int j = 1; j <= n; j++) ansR[j] = R[j];
            for (int j = 1; j <= m; j++) ansC[j] = C[j];
        }
    }
    if (ans >= 0) {
        printf("%d\n", ans);
        for (int j = 1; j <= n; j++) for (int k = 1; k <= ansR[j]; k++) printf("row %d\n", j);
        for (int j = 1; j <= m; j++) for (int k = 1; k <= ansC[j]; k++) printf("col %d\n", j);
    } else {
        printf("-1\n");
    }
    return 0;
}
