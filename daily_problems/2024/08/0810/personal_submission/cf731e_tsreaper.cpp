#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;

long long f[MAXN + 10], sm[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        sm[i] = sm[i - 1] + x;
    }

    long long mx = sm[n];
    for (int i = n - 1; i > 0; i--) {
        f[i] = mx;
        mx = max(mx, sm[i] - f[i]);
    }
    printf("%lld\n", f[1]);
    return 0;
}
