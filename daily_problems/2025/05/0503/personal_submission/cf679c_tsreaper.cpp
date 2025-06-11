#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, K, ans;
char MAP[MAXN + 5][MAXN + 5];

int root[MAXN * MAXN + 5], sz[MAXN * MAXN + 5];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int now, cnt[MAXN * MAXN + 5];

int idx(int i, int j) { return i * n + j; }

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x == y) return;
    root[x] = y;
    sz[y] += sz[x];
}

void add(int i, int j) {
    int r = findroot(idx(i, j));
    int t = ++cnt[r];
    if (t == 1) now += sz[r];
}

void del(int i, int j) {
    int r = findroot(idx(i, j));
    int t = --cnt[r];
    if (t == 0) now -= sz[r];
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) scanf("%s", MAP[i]);

    for (int i = 0; i < n * n; i++) root[i] = i, sz[i] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (MAP[i][j] == '.') {
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii < 0 || jj < 0 || ii >= n || jj >= n || MAP[ii][jj] == 'X') continue;
            merge(idx(i, j), idx(ii, jj));
        }
    }

    for (int r = 0; r + K <= n; r++) {
        now = 0;
        for (int i = 0; i < n * n; i++) cnt[i] = 0;

        for (int i = r; i < r + K; i++) for (int j = 0; j < K; j++) {
            if (MAP[i][j] == 'X') now++;
            else add(i, j);
        }
        for (int i = r; i < r + K; i++) {
            if (K < n && MAP[i][K] == '.') add(i, K);
        }
        for (int j = 0; j < K; j++) {
            if (r - 1 >= 0 && MAP[r - 1][j] == '.') add(r - 1, j);
            if (r + K < n && MAP[r + K][j] == '.') add(r + K, j);
        }

        int j = K - 1;
        while (true) {
            ans = max(ans, now);
            if (j == n - 1) break;
            j++;
            for (int i = r; i < r + K; i++) {
                if (MAP[i][j - K] == 'X') now--;
                if (MAP[i][j] == 'X') now++;
                if (j - K - 1 >= 0 && MAP[i][j - K - 1] == '.') del(i, j - K - 1);
                if (j + 1 < n && MAP[i][j + 1] == '.') add(i, j + 1);
            }
            if (r - 1 >= 0) {
                if (MAP[r - 1][j - K] == '.') del(r - 1, j - K);
                if (MAP[r - 1][j] == '.') add(r - 1, j);
            }
            if (r + K < n) {
                if (MAP[r + K][j - K] == '.') del(r + K, j - K);
                if (MAP[r + K][j] == '.') add(r + K, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
