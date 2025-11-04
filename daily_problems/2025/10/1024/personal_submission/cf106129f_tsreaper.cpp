#include <bits/stdc++.h>
#define MAXN 2500
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

bool flag[MAXN + 5][MAXN + 5];

bool check(int len) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) flag[i][j] = false;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == '#' && !flag[i][j]) {
        for (int di = 0; di < len; di++) for (int dj = 0; dj < len; dj++) {
            int ii = i + di, jj = j + dj;
            if (ii > n || jj > m || MAP[ii][jj] == '.' || flag[ii][jj]) return false;
            flag[ii][jj] = true;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    int tot = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == '#') tot++;
    for (int len = min(n, m); len > 0; len--) if (tot % (len * len) == 0 && check(len)) { printf("%d\n", len); break; }
    return 0;
}
