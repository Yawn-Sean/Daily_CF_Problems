#include <bits/stdc++.h>
#define MAXN 1000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;

long long f[MAXN * 2 + 10][MAXN + 10];
bool g[MAXN * 2 + 10][MAXN + 10];

int main() {
    scanf("%d", &n);
    g[0][0] = true;
    for (int i = 1; i <= n * 2; i++) for (int j = i & 1; j <= n && j <= i; j += 2) {
        bool flag = false;
        if (j > 0) {
            f[i][j] = (f[i][j] + f[i - 1][j - 1]) % MOD;
            flag = flag || g[i - 1][j - 1];
        }
        if (j + 1 <= i - 1) {
            f[i][j] = (f[i][j] + f[i - 1][j + 1]) % MOD;
            flag = flag || g[i - 1][j + 1];
        }
        if (flag) f[i][j] = (f[i][j] + 1) % MOD, g[i][j] = false;
        else g[i][j] = true;
    }
    printf("%lld\n", f[n * 2][0]);
    return 0;
}
