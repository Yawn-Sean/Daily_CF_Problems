#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

int root[MAXN * MAXN + 5], sz[MAXN * MAXN + 5];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x == y) return;
    root[y] = x;
    sz[x] += sz[y];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", MAP[i]);

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        root[i * m + j] = i * m + j;
        if (MAP[i][j] == '.') sz[i * m + j] = 1;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (MAP[i][j] == '.') {
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii < 0 || jj < 0 || ii >= n || jj >= m || MAP[ii][jj] == '*') continue;
            merge(i * m + j, ii * m + jj);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == '*') {
                unordered_map<int, int> mp;
                for (int k = 0; k < 4; k++) {
                    int ii = i + dir[k][0], jj = j + dir[k][1];
                    if (ii < 0 || jj < 0 || ii >= n || jj >= m || MAP[ii][jj] == '*') continue;
                    int r = findroot(ii * m + jj);
                    mp[r] = sz[r];
                }
                int ans = 1;
                for (auto &p : mp) ans += p.second;
                printf("%d", ans % 10);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
