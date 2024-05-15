#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXLEN 8
using namespace std;
 
int n;
char s[MAXN + 10][15];

bool gao(int idx, int pos, int full, int bgn) {
    if (pos >= MAXLEN) return full ? false : true;
    if (s[idx][pos] == '?') {
        int L = full ? s[idx - 1][pos] - '0' : 0;
        for (int i = (bgn ? L : max(L, 1)); i <= 9; i++) {
            int nxtFull = (full && i == L);
            int nxtBgn = (bgn || i > 0);
            if (gao(idx, pos + 1, nxtFull, nxtBgn)) {
                s[idx][pos] = i + '0';
                return true;
            }
        }
        return false;
    } else {
        int L = full ? s[idx - 1][pos] - '0' : 0;
        int d = s[idx][pos] - '0';
        if (d < L) return false;
        int nxtFull = (full && d == L);
        int nxtBgn = (bgn || d > 0);
        return gao(idx, pos + 1, nxtFull, nxtBgn);
    }
}
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < MAXLEN; i++) s[0][i] = '0';
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i]);
        int len = strlen(s[i]);
        for (int x = len - 1, y = MAXLEN - 1; x >= 0; x--, y--) s[i][y] = s[i][x];
        for (int x = MAXLEN - len - 1; x >= 0; x--) s[i][x] = '0';
        if (!gao(i, 0, 1, 0)) { printf("NO\n"); return 0; }
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 0; j < MAXLEN; j++) {
            if (s[i][j] > '0') flag = true;
            if (flag) printf("%c", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
