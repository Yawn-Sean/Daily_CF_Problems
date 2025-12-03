#include <bits/stdc++.h>
#define MAXN 7000
#define MOD 998244353
using namespace std;

int n, A[MAXN + 5];
long long ans;

long long f[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    ans = n;
    for (int i = 1; i <= n; i++) {
        long long sm = 0;
        for (int j = i + 1, k = 1; j <= n; j++) {
            while (k < i && A[k] + A[i] <= A[j]) {
                sm += f[k][i];
                k++;
            }
            f[i][j] = (sm + 1) % MOD;
            ans = (ans + f[i][j]) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
