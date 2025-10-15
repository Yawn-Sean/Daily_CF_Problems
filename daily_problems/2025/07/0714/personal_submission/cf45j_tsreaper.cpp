#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m, ans[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    if (n * m >= 2 && n * m <= 3) { printf("-1\n"); return 0; }
    if (n == 2 && m == 2) { printf("-1\n"); return 0; }

    queue<int> q;
    for (int i = 2; i <= n * m; i += 2) q.push(i);
    for (int i = 1; i <= n * m; i += 2) q.push(i);

    if (n <= m) {
        for (int j = 1; j <= m; j++) for (int i = 1; i <= n; i++)
            ans[i][j] = q.front(), q.pop();
    } else {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            ans[i][j] = q.front(), q.pop();
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) printf("%d%c", ans[i][j], "\n "[j < m]);
    return 0;
}
