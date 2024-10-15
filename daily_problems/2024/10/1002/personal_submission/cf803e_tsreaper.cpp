#include <bits/stdc++.h>
#define MAXN 1000
#define INF ((int) 1e9)
using namespace std;

int n, K;
char s[MAXN + 10];

int f[MAXN + 10][MAXN * 2 + 10];

int main() {
    scanf("%d%d%s", &n, &K, s + 1);
    
    for (int i = 0; i <= n; i++) for (int j = -K; j <= K; j++) f[i][j + K] = -INF;
    f[0][K] = 0;
    for (int i = 1; i <= n; i++) for (int j = -K + (i < n ? 1 : 0); j <= K - (i < n ? 1 : 0); j++) {
        if (s[i] == 'L' || s[i] == '?') if (j + 1 <= K && f[i - 1][j + 1 + K] > -INF) f[i][j + K] = j + 1;
        if (s[i] == 'W' || s[i] == '?') if (j - 1 >= -K && f[i - 1][j - 1 + K] > -INF) f[i][j + K] = j - 1;
        if (s[i] == 'D' || s[i] == '?') if (f[i - 1][j + K] > -INF) f[i][j + K] = j;
    }

    if (f[n][-K + K] > -INF || f[n][K + K] > -INF) {
        int now = (f[n][-K + K] > -INF ? -K : K);
        for (int i = n; i > 0; i--) {
            if (f[i][now + K] == now) s[i] = 'D';
            else if (f[i][now + K] == now + 1) s[i] = 'L';
            else s[i] = 'W';
            now = f[i][now + K];
        }
        printf("%s\n", s + 1);
    } else {
        printf("NO\n");
    }
    return 0;
}
