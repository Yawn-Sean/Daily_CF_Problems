#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
using namespace std;

int n, m, D, E[MAXM + 10][2];

int root[MAXN + 10];
bool used[MAXM + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

bool merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x == y) return false;
    root[x] = y;
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &D);
    for (int i = 1; i <= m; i++) scanf("%d%d", &E[i][0], &E[i][1]);

    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) if (E[i][0] != 1 && E[i][1] != 1) merge(E[i][0], E[i][1]);
    for (int i = 1; i <= m && D > 0; i++) if (E[i][0] == 1 || E[i][1] == 1)
        if (merge(E[i][0], E[i][1])) used[i] = true, D--;
    for (int i = 1; i <= m && D > 0; i++) if (!used[i] && (E[i][0] == 1 || E[i][1] == 1))
        used[i] = true, D--;

    if (D > 0) { printf("NO\n"); return 0; }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (findroot(i) == i) cnt++;
    if (cnt > 1) { printf("NO\n"); return 0; }

    printf("YES\n");
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) if (used[i]) {
        printf("%d %d\n", E[i][0], E[i][1]);
        merge(E[i][0], E[i][1]);
    }
    for (int i = 1; i <= m; i++) if (E[i][0] != 1 && E[i][1] != 1 && merge(E[i][0], E[i][1]))
        printf("%d %d\n", E[i][0], E[i][1]);
    return 0;
}
