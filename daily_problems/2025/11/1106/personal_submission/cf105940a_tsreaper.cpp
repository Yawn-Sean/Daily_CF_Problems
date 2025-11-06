#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

long long f[MAXN + 5][3][3][3][3];

void update(long long &a, long long b) {
    a = (a + b) % MOD;
}

int main() {
    f[0][0][0][0][0] = 1;
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < 3; j++)
        for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++)
            for (int d = 0; d < 3; d++) {
                int w = d % 3;
                int now[] = {a, b, c}, nxt[] = {0, 0, 0};
                for (int t = 0; t < 3; t++) nxt[(t + d) % 3] = now[t];
                nxt[d] = (nxt[d] + 1) % 3;
                int jj = (j + nxt[0]) % 3;

                int cnt;
                if (d == 0) {
                    if (i == 0) cnt = 3;
                    else cnt = 4;
                } else {
                    cnt = 3;
                }
                update(f[i + 1][jj][nxt[0]][nxt[1]][nxt[2]], f[i][j][a][b][c] * cnt);
            }

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        int n; scanf("%d", &n);
        long long ans = 0;
        for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++)
            update(ans, f[n][0][a][b][c]);
        printf("%lld\n", ans);
    }
    return 0;
}
