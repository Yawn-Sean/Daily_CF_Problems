#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, m, q;
bool flag;

int root[MAXN + 5][MAXN + 5], L[MAXN + 5][MAXN + 5], R[MAXN + 5][MAXN + 5];

int findroot(int *root, int x) {
    if (root[x] != x) root[x] = findroot(root, root[x]);
    return root[x];
}

void merge(int *root, int *L, int *R, int a, int b) {
    a = findroot(root, a); b = findroot(root, b);
    root[a] = b;
    L[b] = min(L[a], L[b]);
    R[b] = max(R[a], R[b]);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    if (n > m) swap(n, m), flag = true;
    int MAGIC = sqrt(2 * q) + 1;

    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        if (flag) swap(x, y);
        int best = 1e9, xx = 0, yy = 0;

        auto update = [&](int i, int j) {
            int d = abs(x - i) + abs(y - j);
            if (d < best) best = d, xx = i, yy = j;
            else if (d == best) {
                if (flag) {
                    if (j < yy || (j == yy && i < xx)) xx = i, yy = j;
                } else {
                    if (i < xx || (i == xx && j < yy)) xx = i, yy = j;
                }
            }
        };

        for (int i = max(1, x - MAGIC); i <= n && i <= x + MAGIC; i++) {
            if (root[i][y] == 0) update(i, y);
            else {
                int l = L[i][findroot(root[i], y)] - 1;
                int r = R[i][findroot(root[i], y)] + 1;
                if (l > 0) update(i, l);
                if (r <= m) update(i, r);
            }
        }

        if (flag) printf("%d %d\n", yy, xx);
        else printf("%d %d\n", xx, yy);
        root[xx][yy] = L[xx][yy] = R[xx][yy] = yy;
        if (yy - 1 > 0 && root[xx][yy - 1] > 0) merge(root[xx], L[xx], R[xx], yy, yy - 1);
        if (yy + 1 <= m && root[xx][yy + 1] > 0) merge(root[xx], L[xx], R[xx], yy, yy + 1);
    }
    return 0;
}
