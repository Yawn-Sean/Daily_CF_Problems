#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
using namespace std;

int n, m, K, A[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if (n % 2 == 0) printf("0\n");
    else {
        int x = A[1];
        for (int i = 1; i <= n; i += 2) x = min(x, A[i]);
        int y = (n + 1) / 2;
        int z = m / y;
        printf("%lld\n", min(1LL * x, 1LL * K * z));
    }
    return 0;
}
