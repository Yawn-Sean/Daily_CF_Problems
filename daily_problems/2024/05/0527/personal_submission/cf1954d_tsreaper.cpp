#include <bits/stdc++.h>
#define MAXN 5000
#define MAXA 5000
#define MOD 998244353
using namespace std;

int n, A[MAXN + 10];
long long ans;

long long f[MAXA + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXA; j++)
            if (j <= A[i]) ans = (ans + A[i] * f[j]) % MOD;
            else ans = (ans + (A[i] + j + 1) / 2 * f[j]) % MOD;
        for (int j = MAXA; j >= A[i]; j--) f[j] = (f[j] + f[j - A[i]]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
