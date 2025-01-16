#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXK 10
using namespace std;

int n, K, A[MAXK + 5][MAXN + 5];
long long ans;

int B[MAXK + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= K; i++) for (int j = 1; j <= n; j++) {
        scanf("%d", &A[i][j]);
        B[i][A[i][j]] = j;
    }

    for (int i = 1, j = 1; i <= n; i++) {
        if (i > j) {
            for (int k = 2; k <= K; k++) {
                int ii = B[k][A[1][i]];
                if (A[k][ii - 1] != A[1][i - 1]) { j = i; break; }
            }
        }
        ans += i - j + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
