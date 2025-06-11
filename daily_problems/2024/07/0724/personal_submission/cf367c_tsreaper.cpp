#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int K, n, A[MAXN + 10];

int main() {
    scanf("%d%d", &K, &n);
    for (int i = 1; i <= n; i++) scanf("%*d%d", &A[i]);
    sort(A + 1, A + n + 1, greater<int>());

    long long sm = 0;
    for (int i = 1; i <= n; i++) sm += A[i];

    for (int i = n; i > 0; i--) {
        long long need = 1LL * i * (i - 1) / 2;
        if (i & 1) need++;
        else need += i / 2;
        if (need <= K) { printf("%lld\n", sm); break; }
        sm -= A[i];
    }
    return 0;
}
