#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n;
char MAP[MAXN + 5][MAXN + 5], ans[MAXN * 2 + 5][MAXN * 2 + 5];

bool check(int di, int dj) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (MAP[i][j] == 'o') {
        int ii = i + di, jj = j + dj;
        if (ii > 0 && jj > 0 && ii <= n && jj <= n && MAP[ii][jj] == '.') return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int i = 1; i < n * 2; i++) for (int j = 1; j < n * 2; j++) ans[i][j] = '.';
    for (int di = -n + 1; di < n; di++) for (int dj = -n + 1; dj < n; dj++)
        if (check(di, dj)) ans[di + n][dj + n] = 'x';
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (MAP[i][j] == 'o')
        for (int di = -n + 1; di < n; di++) for (int dj = -n + 1; dj < n; dj++) if (ans[di + n][dj + n] == 'x') {
            int ii = i + di, jj = j + dj;
            if (ii > 0 && jj > 0 && ii <= n && jj <= n && MAP[ii][jj] == 'x') MAP[ii][jj] = '.';
        }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        if (MAP[i][j] == 'x') { printf("NO\n"); return 0; }
    printf("YES\n");
    ans[n][n] = 'o';
    for (int i = 1; i < n * 2; i++) printf("%s\n", ans[i] + 1);
    return 0;
}
