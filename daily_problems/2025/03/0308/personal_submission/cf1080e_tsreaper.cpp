#include <bits/stdc++.h>
#define MAXN 250
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int val[26];

int n, m;
char s[MAXN + 5][MAXN + 5];
long long ans;

int h1[MAXN + 5][MAXN + 5];
long long h2[MAXN + 5][MAXN + 5];
int U[MAXN + 5], D[MAXN + 5], f[2][MAXN + 5];

void manacher(int L, int R) {
    for (int p = 0; p < 2; p++) for (int i = 1, l = 1, r = 0; i <= n; i++) {
        int k = (i > r ? 1 - p : min(f[p][l + r - i + p], r - i + 1));
        while (i - k - p > 0 && i + k <= n) {
            long long x = h2[i - k - p][R] - h2[i - k - p][L - 1];
            long long y = h2[i + k][R] - h2[i + k][L - 1];
            if (x != y) break;
            k++;
        }
        f[p][i] = k--;
        if (i + k > r) l = i - k - p, r = i + k;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);

    for (int i = 0; i < 26; i++) val[i] = rnd(1, 1e9);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int c = s[i][j] - 'a';
        h1[i][j] = h1[i][j - 1] ^ (1 << c);
        h2[i][j] = h2[i][j - 1] + val[c];
    }

    for (int l = 1; l <= m; l++) for (int r = l; r <= m; r++) {
        for (int i = 1, j = 1; i <= n; i++) {
            int h = h1[i][r] ^ h1[i][l - 1];
            if (__builtin_popcount(h) > 1) j = i + 1;
            U[i] = j;
        }
        for (int i = n, j = n; i > 0; i--) {
            int h = h1[i][r] ^ h1[i][l - 1];
            if (__builtin_popcount(h) > 1) j = i - 1;
            D[i] = j;
        }

        manacher(l, r);
        for (int i = 1; i <= n; i++) if (U[i] <= D[i]) {
            ans += min({f[0][i], i - U[i] + 1, D[i] - i + 1});
            ans += min({f[1][i], i - U[i], D[i] - i + 1});
        }
    }
    printf("%lld\n", ans);
    return 0;
}
