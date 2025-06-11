#include <bits/stdc++.h>
#define MAXN 5000
#define MOD 998244353
using namespace std;

int n, A[MAXN + 5];

long long P[MAXN + 5], f[2][MAXN + 5][2];

void update(long long &a, long long b) { a = (a + b) % MOD; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;
    f[1][1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) f[i & 1 ^ 1][j][0] = f[i & 1 ^ 1][j][1] = 0;
        for (int j = i; j > 0; j--) {
            for (int k = 0; k < 2; k++) update(f[i & 1][j - 1][1], f[i & 1][j][k]);
            if (i < n) {
                if (A[i + 1] > A[i]) update(f[i & 1 ^ 1][j + 1][0], f[i & 1][j][0] * P[j - 1] % MOD);
                update(f[i & 1 ^ 1][j + 1][0], f[i & 1][j][1] * P[j - 1] % MOD);
            }
        }
    }
    printf("%lld\n", f[n & 1][0][1]);
    return 0;
}
