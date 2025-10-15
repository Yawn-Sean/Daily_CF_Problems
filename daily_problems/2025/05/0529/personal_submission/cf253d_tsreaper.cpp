#include <bits/stdc++.h>
#define MAXN 400
using namespace std;

int n, m, K;
long long ans;
char MAP[MAXN + 5][MAXN + 5];

int f[MAXN + 5][MAXN + 5];

int query(int i1, int j1, int i2, int j2) {
    return f[i2][j2] - f[i1 - 1][j2] - f[i2][j1 - 1] + f[i1 - 1][j1 - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] = f[i][j - 1] + (MAP[i][j] == 'a' ? 1 : 0);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] += f[i - 1][j];

    for (int u = 1; u <= n; u++) for (int d = u + 1; d <= n; d++) {
        vector<int> pos[26];
        for (int j = 1; j <= m; j++) if (MAP[u][j] == MAP[d][j]) pos[MAP[u][j] - 'a'].push_back(j);
        for (int c = 0; c < 26; c++) for (int i = 0, j = 0; i < pos[c].size(); i++) {
            while (j < i && query(u, pos[c][j], d, pos[c][i]) > K) j++;
            ans += i - j;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
