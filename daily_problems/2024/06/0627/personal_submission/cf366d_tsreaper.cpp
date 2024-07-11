#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 3000
using namespace std;

int n, m, ans;
array<int, 4> E[MAXM + 10];

int root[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

int gao(int R) {
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) if (E[i][3] >= R) {
        int x = E[i][0], y = E[i][1];
        x = findroot(x); y = findroot(y);
        if (x != y) root[x] = y;
        if (findroot(1) == findroot(n)) return R - E[i][2] + 1;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) for (int j = 0; j < 4; j++) scanf("%d", &E[i][j]);
    sort(E + 1, E + m + 1, [&](array<int, 4> &a, array<int, 4> &b) {
        return a[2] < b[2];
    });

    for (int i = 1; i <= m; i++) ans = max(ans, gao(E[i][3]));
    if (ans == 0) printf("Nice work, Dima!\n");
    else printf("%d\n", ans);
    return 0;
}
