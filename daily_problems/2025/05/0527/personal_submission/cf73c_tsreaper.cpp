#include <bits/stdc++.h>
#define MAXN 100
#define INF ((long long) 1e18)
using namespace std;

int n, K, A[26][26];
char s[MAXN + 5];
long long ans;

long long f[MAXN + 5][MAXN + 5][26];

int main() {
    scanf("%s%d", s + 1, &K);
    n = strlen(s + 1);
    int m; scanf("%d", &m);
    while (m--) {
        char s1[3], s2[3];
        int w; scanf("%s%s%d", s1, s2, &w);
        A[s1[0] - 'a'][s2[0] - 'a'] = w;
    }

    for (int i = 0; i <= n; i++) for (int j = 0; j <= K; j++) for (int c = 0; c < 26; c++) f[i][j][c] = -INF;
    for (int c = 0; c < 26; c++) {
        if (c == s[1] - 'a') f[1][0][c] = 0;
        else f[1][1][c] = 0;
    }
    for (int i = 2; i <= n; i++) for (int j = 0; j <= K; j++) for (int c = 0; c < 26; c++) {
        int jj = (s[i] - 'a' == c ? j : j - 1);
        if (jj < 0) continue;
        for (int cc = 0; cc < 26; cc++) f[i][j][c] = max(f[i][j][c], f[i - 1][jj][cc] + A[cc][c]);
    }

    ans = -INF;
    for (int j = 0; j <= K; j++) for (int c = 0; c < 26; c++) ans = max(ans, f[n][j][c]);
    printf("%lld\n", ans);
    return 0;
}
