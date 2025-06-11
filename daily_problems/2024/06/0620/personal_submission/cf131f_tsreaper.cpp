#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, m, K;
long long ans;
char MAP[MAXN + 10][MAXN + 10];

int f[MAXN + 10][MAXN + 10];
short dir[5][2] = {0, 0, 0, 1, 1, 0, -1, 0, 0, -1};

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 2; i < n; i++) for (int j = 2; j < m; j++) {
        int cnt = 0;
        for (int k = 0; k < 5; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            cnt += MAP[ii][jj] - '0';
        }
        f[i][j] = f[i - 1][j];
        if (cnt == 5) f[i][j]++;
    }

    for (int u = 1; u <= n; u++) for (int d = u + 2; d <= n; d++) {
        int now = 0;
        for (int i = 2, j = 2; i < m; i++) {
            while (j < m && now < K) {
                now += f[d - 1][j] - f[u][j];
                j++;
            }
            if (now >= K) ans += m - j + 1;
            now -= f[d - 1][i] - f[u][i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
