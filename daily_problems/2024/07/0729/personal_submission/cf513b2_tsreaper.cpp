#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, A[MAXN + 10];
long long K;

int main() {
    scanf("%d%lld", &n, &K);
    for (int i = 1, L = 1, R = n; i <= n; i++) {
        long long t = 1LL << max(n - i - 1, 0);
        if (K <= t) A[L] = i, L++;
        else K -= t, A[R] = i, R--;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
