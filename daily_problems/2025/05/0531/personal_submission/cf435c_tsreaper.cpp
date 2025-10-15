#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, A[MAXN + 5];
char MAP[MAXN * 2 + 5][MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1, x = 1002, y = 0; i <= n; i++) {
        if (i & 1) {
            for (int t = 1; t <= A[i]; t++) {
                y++;
                MAP[x][y] = '/';
                if (t < A[i]) x--;
            }
        } else {
            for (int t = 1; t <= A[i]; t++) {
                y++;
                MAP[x][y] = '\\';
                if (t < A[i]) x++;
            }
        }
    }

    int u = 1e9, d = 0, l = 1e9, r = 0;
    for (int i = 1; i < MAXN * 2 + 5; i++) for (int j = 1; j < MAXN + 5; j++) if (MAP[i][j]) {
        u = min(u, i); d = max(d, i);
        l = min(l, j); r = max(r, j);
    }
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            if (MAP[i][j]) printf("%c", MAP[i][j]);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
