#include <bits/stdc++.h>
#define MAXN 500
#define MAXP 9
using namespace std;

int n, m, ans;
char MAP[MAXN + 5][MAXN + 5];

bool f[MAXP][MAXN + 5][MAXN + 5];
int g[MAXN + 5][MAXN + 5];
short dir[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};

bool black(int i, int j, int len) {
    return g[i + len - 1][j + len - 1] - g[i - 1][j + len - 1] - g[i + len - 1][j - 1] + g[i - 1][j - 1] == len * len;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) g[i][j] = g[i][j - 1] + (MAP[i][j] == '*' ? 1 : 0);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) g[i][j] += g[i - 1][j];

    for (int d = 0; d < 16; d++) {
        for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
            f[1][i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ii = i + dir[k][0], jj = j + dir[k][1];
                if ((d >> k & 1) && MAP[ii][jj] == '.') { f[1][i][j] = false; break; }
                if ((d >> k & 1 ^ 1) && MAP[ii][jj] != '.') { f[1][i][j] = false; break; }
            }
        }
        for (int len = 4, p = 2; len <= min(n, m); len *= 2, p++) {
            for (int i = 1; i + len - 1 <= n; i++) for (int j = 1; j + len - 1 <= m; j++) {
                f[p][i][j] = true;
                for (int k = 0; k < 4; k++) {
                    int ii = i + dir[k][0] * (len / 2), jj = j + dir[k][1] * (len / 2);
                    if ((d >> k & 1) && !black(ii, jj, len / 2)) { f[p][i][j] = false; break; }
                    if ((d >> k & 1 ^ 1) && !f[p - 1][ii][jj]) { f[p][i][j] = false; break; }
                }
                if (f[p][i][j]) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
