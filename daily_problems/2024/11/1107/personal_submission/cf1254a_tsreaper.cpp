#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
using namespace std;

int n, m, K;
char MAP[MAXN + 10][MAXM + 10];

int chr(int x) {
    if (x <= 26) return 'A' + x - 1;
    else if (x <= 26 * 2) return 'a' + x - 27;
    else return '0' + x - 26 * 2 - 1;
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 'R') cnt++;

    int i = 1, j = 1;
    for (int c = 1; c <= K; c++) {
        int goal = cnt / K;
        if (c <= cnt % K) goal++;
        while (goal > 0 || (c == K && i <= n)) {
            if (MAP[i][j] == 'R') goal--;
            MAP[i][j] = chr(c);
            if (i & 1) {
                if (j == m) i++;
                else j++;
            } else {
                if (j == 1) i++;
                else j--;
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%s\n", MAP[i] + 1);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
