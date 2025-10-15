#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];
vector<array<int, 3>> ans;

int U[MAXN + 5][MAXN + 5], D[MAXN + 5][MAXN + 5], L[MAXN + 5][MAXN + 5], R[MAXN + 5][MAXN + 5];
int f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (MAP[i][j] == '.') U[i][j] = L[i][j] = 0;
        else U[i][j] = U[i - 1][j] + 1, L[i][j] = L[i][j - 1] + 1;
    }
    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) {
        if (MAP[i][j] == '.') D[i][j] = R[i][j] = 0;
        else D[i][j] = D[i + 1][j] + 1, R[i][j] = R[i][j + 1] + 1;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int len = min({U[i][j], D[i][j], L[i][j], R[i][j]}) - 1;
        if (len > 0) {
            ans.push_back({i, j, len});
            f[i - len][j]++; f[i + len + 1][j]--;
            g[i][j - len]++; g[i][j + len + 1]--;
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        f[i][j] += f[i - 1][j]; g[i][j] += g[i][j - 1];
        if (MAP[i][j] == '*' && f[i][j] == 0 && g[i][j] == 0) { printf("-1\n"); return 0; }
    }
    printf("%d\n", ans.size());
    for (auto &arr : ans) printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}
