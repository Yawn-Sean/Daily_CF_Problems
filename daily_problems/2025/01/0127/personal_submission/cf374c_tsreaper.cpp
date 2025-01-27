#include <bits/stdc++.h>
#define MAXN 1000
#define INF ((int) 1e9)
using namespace std;

int n, m, ans, MAP[MAXN + 5][MAXN + 5];
char s[MAXN + 5];

int f[MAXN + 5][MAXN + 5];
bool inS[MAXN + 5][MAXN + 5];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int dp(int i, int j) {
    if (inS[i][j]) { printf("Poor Inna!\n"); exit(0); }
    if (f[i][j] > -INF) return f[i][j];

    inS[i][j] = true;
    int &ret = f[i][j];
    ret = (MAP[i][j] == 3 ? 1 : -INF + 10);

    for (int k = 0; k < 4; k++) {
        int ii = i + dir[k][0], jj = j + dir[k][1];
        if (ii <= 0 || jj <= 0 || ii > n || jj > m || (MAP[i][j] + 1) % 4 != MAP[ii][jj]) continue;
        ret = max(ret, dp(ii, jj) + 1);
    }

    inS[i][j] = false;
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == 'D') MAP[i][j] = 0;
            else if (s[j] == 'I') MAP[i][j] = 1;
            else if (s[j] == 'M') MAP[i][j] = 2;
            else MAP[i][j] = 3;
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] = -INF;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 0)
        ans = max(ans, dp(i, j) / 4);
    if (ans == 0) printf("Poor Dima!\n");
    else printf("%d\n", ans);
    return 0;
}
