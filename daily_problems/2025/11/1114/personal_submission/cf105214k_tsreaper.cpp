#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
char MAP[MAXN + 5][MAXN + 5];

void gao(int b, int len) {
    if (len <= 1) return;
    if (len == 2) {
        MAP[b][b] = MAP[b][b + 1] = '#';
        return;
    }
    if (len == 3) {
        MAP[b][b] = MAP[b + 1][b] = '#';
        MAP[b][b + 2] = MAP[b + 1][b + 2] = '#';
        return;
    }

    if (len & 1) {
        for (int i = 0; i < len; i += 2) {
            MAP[b + i][b] = MAP[b + i][b + 1] = '#';
            MAP[b + i][b + len - 1] = MAP[b + i][b + len - 2] = '#';
        }
        for (int j = 3; j < len - 3; j += 2) {
            MAP[b][b + j] = MAP[b + 1][b + j] = '#';
            MAP[b + len - 1][b + j] = MAP[b + len - 2][b + j] = '#';
        }
    } else {
        for (int j = 0; j < len - 3; j += 2) {
            MAP[b][b + j] = MAP[b + 1][b + j] = '#';
            MAP[b + len - 1][b + len - 1 - j] = MAP[b + len - 2][b + len - 1 - j] = '#';
        }
        for (int i = 3; i < len; i += 2) {
            MAP[b + i][b] = MAP[b + i][b + 1] = '#';
            MAP[b + len - 1 - i][b + len - 1] = MAP[b + len - 1 - i][b + len - 2] = '#';
        }
    }
    gao(b + 3, len - 6);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) MAP[i][j] = '.';
    gao(1, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%c", MAP[i][j]);
        printf("\n");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
