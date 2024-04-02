#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
#define MAXP 30
using namespace std;

int n, m, R[MAXN + 10], C[MAXM + 10], ans[MAXN + 10][MAXM + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &R[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &C[i]);

    for (int p = 0; p < MAXP; p++) {
        vector<int> r, c;
        for (int i = 1; i <= n; i++) if (R[i] >> p & 1) r.push_back(i);
        for (int i = 1; i <= m; i++) if (C[i] >> p & 1) c.push_back(i);
        if (r.size() % 2 != c.size() % 2) { printf("NO\n"); return 0; }
        if (r.size() % 2) {
            for (int i : r) for (int j : c) ans[i][j] |= 1 << p;
        } else if (r.size() > 0 && c.size() > 0) {
            for (int i : r) if (i != r.back()) for (int j : c) if (j != c.back()) ans[i][j] |= 1 << p;
            ans[r.back()][c.back()] |= 1 << p;
        } else if (r.size() > 0) {
            for (int i : r) ans[i][1] |= 1 << p;
        } else {
            for (int j : c) ans[1][j] |= 1 << p;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) printf("%d%c", ans[i][j], "\n "[j < m]);
    return 0;
}
