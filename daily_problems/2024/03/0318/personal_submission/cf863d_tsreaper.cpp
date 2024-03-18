#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXQ ((int) 2e5)
using namespace std;

int n, q, m, A[MAXN + 10], OP[MAXQ + 10][3];

int main() {
    scanf("%d%d%d", &n, &q, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= q; i++) scanf("%d%d%d", &OP[i][0], &OP[i][1], &OP[i][2]);

    while (m--) {
        int x; scanf("%d", &x);
        for (int i = q; i > 0; i--) {
            if (x < OP[i][1] || x > OP[i][2]) continue;
            if (OP[i][0] == 1) {
                if (x == OP[i][1]) x = OP[i][2];
                else x--;
            } else {
                int d = x - OP[i][1];
                x = OP[i][2] - d;
            }
        }
        printf("%d ", A[x]);
    }
    printf("\n");
    return 0;
}
