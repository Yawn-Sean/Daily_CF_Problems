#include <bits/stdc++.h>
#define MAXN 60
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

int R[MAXN + 5], C[MAXN + 5];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n; i++) R[i] = 0;
    for (int j = 1; j <= m; j++) C[j] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (MAP[i][j] == 'A') R[i]++, C[j]++;
        cnt += R[i];
    }
    if (cnt == n * m) { printf("0\n"); return; }
    if (cnt == 0) { printf("MORTAL\n"); return; }

    if (R[1] == m || R[n] == m || C[1] == n || C[m] == n) { printf("1\n"); return; }
    for (int i = 2; i < n; i++) if (R[i] == m) { printf("2\n"); return; }
    for (int j = 2; j < m; j++) if (C[j] == n) { printf("2\n"); return; }

    if (MAP[1][1] == 'A' || MAP[1][m] == 'A' || MAP[n][1] == 'A' || MAP[n][m] == 'A') { printf("2\n"); return; }
    if (R[1] > 0 || R[n] > 0 || C[1] > 0 || C[m] > 0) { printf("3\n"); return; }
    printf("4\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
