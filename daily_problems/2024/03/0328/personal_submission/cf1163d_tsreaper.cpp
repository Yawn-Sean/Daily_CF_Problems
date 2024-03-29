#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 50
#define INF ((int) 1e9)
using namespace std;

int n, m1, m2, ans;
char s[MAXN + 10], s1[MAXM + 10], s2[MAXM + 10];

int ch1[MAXM + 10][26], ch2[MAXM + 10][26], f[2][MAXM + 10][MAXM + 10];

void gao(char *s, int n, int ch[][26]) {
    int f[MAXM + 10] = {0};
    for (int i = 1; i <= n; i++) {
        int j = f[i];
        while (j > 0 && s[j + 1] != s[i + 1]) j = f[j];
        if (s[j + 1] == s[i + 1]) j++;
        f[i + 1] = j;
    }

    for (int i = 0; i <= n; i++) for (int c = 0; c < 26; c++) {
        int j = i;
        while (j > 0 && s[j + 1] != c + 'a') j = f[j];
        if (s[j + 1] == c + 'a') ch[i][c] = j + 1;
        else ch[i][c] = 0;
    }
}

int main() {
    scanf("%s%s%s", s + 1, s1 + 1, s2 + 1);
    n = strlen(s + 1); m1 = strlen(s1 + 1); m2 = strlen(s2 + 1);
    gao(s1, m1, ch1); gao(s2, m2, ch2);

    for (int j = 0; j <= m1; j++) for (int k = 0; k <= m2; k++) f[0][j][k] = -INF;
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m1; j++) for (int k = 0; k <= m2; k++) f[i & 1 ^ 1][j][k] = -INF;
        for (int j = 0; j <= m1; j++) for (int k = 0; k <= m2; k++) for (int c = 0; c < 26; c++) {
            if (s[i + 1] != '*' && s[i + 1] != c + 'a') continue;
            int jj = ch1[j][c], kk = ch2[k][c];
            int v = f[i & 1][j][k];
            if (jj == m1) v++;
            if (kk == m2) v--;
            f[i & 1 ^ 1][jj][kk] = max(f[i & 1 ^ 1][jj][kk], v);
        }
    }
    
    ans = -INF;
    for (int j = 0; j <= m1; j++) for (int k = 0; k <= m2; k++) ans = max(ans, f[n & 1][j][k]);
    printf("%d\n", ans);
    return 0;
}
