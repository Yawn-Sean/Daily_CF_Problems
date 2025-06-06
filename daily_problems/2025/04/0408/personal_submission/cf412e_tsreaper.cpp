#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, A[MAXN + 5];
long long ans;
char s[MAXN + 5];

int prv[MAXN + 5][5], nxt[MAXN + 5][5], f[MAXN + 5][2];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') A[i] = 0;
        else if (s[i] >= '0' && s[i] <= '9') A[i] = 1;
        else if (s[i] == '.') A[i] = 2;
        else if (s[i] == '_') A[i] = 3;
        else A[i] = 4;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) prv[i][j] = prv[i - 1][j];
        prv[i][A[i]] = i;
    }
    for (int j = 0; j < 5; j++) nxt[n + 1][j] = n + 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 5; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][A[i]] = i;
    }
    for (int i = 1; i <= n; i++) for (int j = 0; j < 2; j++) f[i][j] = f[i - 1][j] + (A[i] == j ? 1 : 0);

    for (int i = 1; i <= n; i++) if (s[i] == '@') {
        int dot = nxt[i + 1][2];
        if (dot > n) continue;

        int sm = 0;
        for (int j = 0; j < 2; j++) sm += f[dot][j] - f[i][j];
        if (sm == 0 || sm != dot - i - 1) continue;

        int r = n + 1;
        for (int j = 1; j < 5; j++) r = min(r, nxt[dot + 1][j]);

        int l = max(prv[i - 1][2], prv[i - 1][4]);

        ans += 1LL * (f[i][0] - f[l][0]) * (r - dot - 1);
    }

    printf("%lld\n", ans);
    return 0;
}
