#include <bits/stdc++.h>
#define MAXN 16
#define MAGIC 120
#define INF ((int) 1e9)
using namespace std;
 
int n, A[MAXN][3];
long long ans;
 
int f[1 << MAXN][MAGIC + 5];
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[3]; scanf("%s%d%d", s, &A[i][1], &A[i][2]);
        if (s[0] == 'R') A[i][0] = 0;
        else A[i][0] = 1;
    }
 
    for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= MAGIC; j++) f[i][j] = -INF;
    f[0][0] = 0;
    for (int i = 0; i + 1 < (1 << n); i++) for (int j = 0; j <= MAGIC; j++) {
        int cnt[2] = {0};
        for (int k = 0; k < n; k++) if (i >> k & 1) cnt[A[k][0]]++;
        for (int k = 0; k < n; k++) if (i >> k & 1 ^ 1) {
            int ii = i | (1 << k);
            int r = min(A[k][1], cnt[0]), b = min(A[k][2], cnt[1]);
            f[ii][j + r] = max(f[ii][j + r], f[i][j] + b);
        }
    }
 
    long long r = 0, b = 0;
    for (int i = 0; i < n; i++) r += A[i][1], b += A[i][2];
    ans = max(r, b);
    for (int j = 0; j <= MAGIC; j++) ans = min(ans, max(r - j, b - f[(1 << n) - 1][j]));
    printf("%lld\n", ans + n);
    return 0;
}
