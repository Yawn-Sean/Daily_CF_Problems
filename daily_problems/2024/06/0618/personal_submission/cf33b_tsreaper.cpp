#include <bits/stdc++.h>
#define MAXLEN ((int) 1e5)
#define SIGMA 26
#define INF ((int) 1e9)
using namespace std;

char s1[MAXLEN + 10], s2[MAXLEN + 10], s3[MAXLEN + 10];

int g[SIGMA + 5][SIGMA + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    if (strlen(s1 + 1) != strlen(s2 + 1)) { printf("-1\n"); return 0; }

    for (int i = 0; i < SIGMA; i++) for (int j = 0; j < SIGMA; j++) g[i][j] = INF;
    for (int i = 0; i < SIGMA; i++) g[i][i] = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char x[3], y[3];
        int d; scanf("%s%s%d", x, y, &d);
        int sn = x[0] - 'a', fn = y[0] - 'a';
        g[sn][fn] = min(g[sn][fn], d);
    }
    for (int k = 0; k < SIGMA; k++) for (int i = 0; i < SIGMA; i++) for (int j = 0; j < SIGMA; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int ans = 0;
    for (int i = 1; s1[i]; i++) {
        char best;
        int val = INF;
        int x = s1[i] - 'a', y = s2[i] - 'a';
        for (int c = 0; c < SIGMA; c++) if (g[x][c] + g[y][c] < val)
            best = c + 'a', val = g[x][c] + g[y][c];
        if (val < INF) s3[i] = best, ans += val;
        else { printf("-1\n"); return 0; }
    }
    printf("%d\n%s\n", ans, s3 + 1);
    return 0;
}
