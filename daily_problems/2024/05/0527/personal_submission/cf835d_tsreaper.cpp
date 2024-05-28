#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, ans[MAXN + 10];
char s[MAXN + 10];

int f[MAXN + 10][MAXN + 10];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);

    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int i = 1; i < n; i++) if (s[i] == s[i + 1]) f[i][i + 1] = 2;
    for (int len = 3; len <= n; len++) for (int l = 1, r = len; r <= n; l++, r++) if (f[l + 1][r - 1] && s[l] == s[r]) {
        int t = l + len / 2 - 1;
        f[l][r] = f[l][t] + 1;
    }

    for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) ans[f[l][r]]++;
    for (int i = n; i > 0; i--) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
