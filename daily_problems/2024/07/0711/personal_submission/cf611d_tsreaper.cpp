#include <bits/stdc++.h>
#define MAXN 5000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
char s[MAXN + 10];

int lcp[MAXN + 10][MAXN + 10], f[MAXN + 10][MAXN + 10];

int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = n; i > 0; i--) for (int j = i; j <= n; j++) {
        if (s[i] != s[j]) lcp[i][j] = 0;
        else lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) if (s[i - j + 1] != '0') {
            int x = i - j * 2 + 1, y = i - j + 1;
            if (x > 0 && lcp[x][y] < j && s[x + lcp[x][y]] < s[y + lcp[x][y]])
                f[i][j] = f[i - j][j];
            else
                f[i][j] = f[i - j][j - 1];
        }
        f[i][i] = 1;
        for (int j = 1; j <= n; j++) f[i][j] = (f[i][j - 1] + f[i][j]) % MOD;
    }
    printf("%d\n", f[n][n]);
    return 0;
}
