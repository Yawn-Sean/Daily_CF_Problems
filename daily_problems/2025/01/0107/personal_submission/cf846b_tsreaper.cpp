#include <bits/stdc++.h>
#define MAXN 45
using namespace std;

int n, m, K, A[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    long long sm = 0;
    for (int i = 1; i <= m; i++) scanf("%d", &A[i]), sm += A[i];
    sort(A + 1, A + m + 1);

    int ans = 0;
    for (int i = 0; i <= n && sm * i <= K; i++) {
        int now = i * (m + 1);
        long long rem = K - sm * i;
        for (int j = 1; j <= m; j++) {
            long long t = min((long long) n - i, rem / A[j]);
            now += t;
            rem -= A[j] * t;
        }
        ans = max(ans, now);
    }
    printf("%d\n", ans);
    return 0;
}
