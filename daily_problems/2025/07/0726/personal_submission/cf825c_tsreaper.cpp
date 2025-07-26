#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, K, ans, A[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    long long now = K;
    for (int i = 1; i <= n; i++) {
        while (now * 2 < A[i]) {
            ans++;
            now *= 2;
        }
        now = max(now, 1LL * A[i]);
    }
    printf("%d\n", ans);
    return 0;
}
