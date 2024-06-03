#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK 1000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
long long ans;

long long f[MAXK + 10][MAXN + 10];

void update(long long &a, long long b) { a = (a + b) % MOD; }

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= K; i++) for (int j = 0; j <= n + 1; j++) f[i][j] = 0;
    ans = 0;
    f[K][0] = 1;
    for (int i = K; i > 0; i--) {
        if (i % 2 == K % 2) {
            for (int j = 0; j < n; j++) {
                update(f[i][j + 1], f[i][j]);
                update(f[i - 1][j + 1], f[i][j]);
            }
            update(ans, f[i][n]);
        } else {
            for (int j = n + 1; j > 1; j--) {
                update(f[i][j - 1], f[i][j]);
                update(f[i - 1][j - 1], f[i][j]);
            }
            update(ans, f[i][1]);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
