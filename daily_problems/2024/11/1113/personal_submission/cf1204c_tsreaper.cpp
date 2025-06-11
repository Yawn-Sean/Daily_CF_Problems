#include <bits/stdc++.h>
#define MAXN 100
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

int n, m;
char MAP[MAXN + 5][MAXN + 5];
vector<pii> ans;

int g[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", MAP[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (i == j) g[i][j] = 0;
            else if (MAP[i][j] == '1') g[i][j] = 1;
            else g[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= n; i++) g[i][i] = INF;

    scanf("%d", &m);
    int last;
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        if (i == 1) { ans.push_back({x, i}); continue; }
        if (g[ans.back().first][x] != i - ans.back().second) ans.push_back({last, i - 1});
        last = x;
    }
    ans.push_back({last, m});

    printf("%d\n", ans.size());
    for (pii p : ans) printf("%d ", p.first);
    printf("\n");
    return 0;
}
