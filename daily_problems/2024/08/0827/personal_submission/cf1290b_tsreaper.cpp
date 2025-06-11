#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q;
char s[MAXN + 10];

int f[MAXN + 10][26];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) f[i][c] = f[i - 1][c];
        f[i][s[i] - 'a']++;
    }

    scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        if (l == r) { printf("Yes\n"); continue; }
        int cnt = 0;
        for (int c = 0; c < 26; c++) {
            int t = f[r][c] - f[l - 1][c];
            if (t > 0) cnt++;
        }
        if (cnt > 2) printf("Yes\n");
        else if (cnt == 1) printf("No\n");
        else if (s[l] != s[r]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
