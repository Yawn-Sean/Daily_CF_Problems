#include <bits/stdc++.h>
#define MAXN 500
#define INF ((int) 1e9)
using namespace std;

int n, m;
char sn[MAXN + 10], sm[MAXN + 10];

int nxt[MAXN + 10][2], f[2][MAXN + 10][MAXN + 10];

bool check(int i, int x, int j) {
    for (int k = j; k > 0; k--) {
        int c = (k == j ? x : sm[i + 1 - (j - k)] - '0');
        if (c != sm[k] - '0') return false;
    }
    return true;
}

void update(int &x, int y) { x = min(x, y); }

int main() {
    scanf("%d%d%s%s", &n, &m, sn + 1, sm + 1);

    if (m == 1) {
        int cnt[2] = {0};
        for (int i = 1; i <= n; i++) cnt[sn[i] - '0']++;
        for (int i = 0; i <= n - m + 1; i++) printf("%d%c", abs(i - cnt[sm[1] - '0']), "\n "[i < n - m + 1]);
        return 0;
    }

    nxt[0][sm[1] - '0'] = 1;
    for (int i = 1; i < m; i++) {
        int x = sm[i + 1] - '0';
        if (i != m - 1) nxt[i][x] = i + 1;
        else for (int j = i; j > 0; j--) if (check(i, x, j)) { nxt[i][x] = j; break; }
        for (int j = i; j > 0; j--) if (check(i, x ^ 1, j)) { nxt[i][x ^ 1] = j; break; }
    }

    for (int j = 0; j <= n; j++) for (int k = 0; k < m; k++) f[0][j][k] = INF;
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) for (int k = 0; k < m; k++) f[i & 1 ^ 1][j][k] = INF;
        for (int j = 0; j <= n; j++) for (int k = 0; k < m; k++) {
            int c = sn[i + 1] - '0';
            int jj = j;
            if (k == m - 1 && c == sm[m] - '0') jj++;
            update(f[i & 1 ^ 1][jj][nxt[k][c]], f[i & 1][j][k]);

            jj = j;
            if (k == m - 1 && 1 - c == sm[m] - '0') jj++;
            update(f[i & 1 ^ 1][jj][nxt[k][c ^ 1]], f[i & 1][j][k] + 1);
        }
    }

    for (int j = 0; j <= n - m + 1; j++) {
        int ans = INF;
        for (int k = 0; k < m; k++) ans = min(ans, f[n & 1][j][k]);
        printf("%d%c", ans < INF ? ans : -1, "\n "[j < n - m + 1]);
    }
    return 0;
}
