#include <bits/stdc++.h>
#define MAXN ((int) 5e4)
using namespace std;

int n;
long long K, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]), K += A[i];
    K /= n;

    long long now = 0, ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        if (A[i] > K) {
            while (j < i && A[i] > K) {
                if (A[j] < K) {
                    long long t = min(K - A[j], A[i] - K);
                    A[j] += t;
                    A[i] -= t;
                    ans += t * (i - j);
                } else {
                    j++;
                }
            }
            now += A[i] - K;
            A[i] = K;
        } else if (A[i] < K) {
            long long t = min(K - A[i], now);
            A[i] += t;
            now -= t;
        }
        ans += now;
    }
    printf("%lld\n", ans);
    return 0;
}
