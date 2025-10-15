#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q;

int root[2][MAXN + 5], R[MAXN + 5];

int findroot(int *root, int x) {
    if (root[x] != x) root[x] = findroot(root, root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(root[0], x); y = findroot(root[0], y);
    if (x != y) root[0][y] = x;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) root[0][i] = root[1][i] = i, R[i] = i;
    while (q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            merge(x, y);
        } else if (op == 2) {
            int b = findroot(root[1], x);
            for (int i = x; i <= y; i++) {
                int t = findroot(root[1], i);
                i = R[t];
                merge(x, i);
                root[1][t] = b;
                R[b] = i;
            }
        } else {
            x = findroot(root[0], x); y = findroot(root[0], y);
            if (x == y) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
