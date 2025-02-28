#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

int main() {
    scanf("%d", &n);

    long long sm = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), sm += A[i];
    sort(A + 1, A + n + 1);

    for (int i = 1; i <= n; i++) {
        sm += 1LL * (A[i] - A[i - 1]) * i;
        sm -= 1LL * (A[i] - A[i - 1]) * (n + 1 - i);
        ans += sm;
    }
    long long g = gcd(ans, n);
    printf("%lld %lld\n", ans / g, n / g);
    return 0;
}
