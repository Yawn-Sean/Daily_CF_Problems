#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;
char s[MAXN + 5];

long long f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%s", s);

    f[0] = A[0];
    for (int i = 1; i < n; i++) f[i] = f[i - 1] + A[i];

    long long sm = 0;
    for (int i = n - 1; i >= 0; i--) if (s[i] == '1') {
        ans = max(ans, sm + (i > 0 ? f[i - 1] : 0));
        sm += A[i];
    }
    ans = max(ans, sm);
    printf("%lld\n", ans);
    return 0;
}
