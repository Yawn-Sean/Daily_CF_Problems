#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m;
char s1[MAXN + 5], s2[MAXN + 5];

int L[MAXN + 5], R[MAXN + 5], f[MAXN + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1); m = strlen(s2 + 1);

    for (int i = 1, j = 1; i <= m; i++) {
        while (j <= n && s1[j] != s2[i]) j++;
        if (j > n) { printf("No\n"); return 0; }
        L[i] = j++;
    }

    for (int i = 0; i < 26; i++) R[i] = 0;
    for (int i = m, j = n; i > 0; i--) {
        while (j > 0 && s1[j] != s2[i]) j--;
        if (j == 0) { printf("No\n"); return 0; }
        R[i] = j--;
    }

    for (int c = 0; c < 26; c++) {
        for (int i = 1; i <= n; i++) f[i] = 0;
        for (int i = 1; i <= m; i++) if (s2[i] == c + 'a')
            f[L[i]]++, f[R[i] + 1]--;
        for (int i = 1; i <= n; i++) {
            f[i] += f[i - 1];
            if (s1[i] == c + 'a' && f[i] == 0) { printf("No\n"); return 0; }
        }
    }
    printf("Yes\n");
    return 0;
}
