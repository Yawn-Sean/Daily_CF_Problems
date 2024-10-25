#include <bits/stdc++.h>
#define MAXN 90
#define INF ((long long) 4e18)
using namespace std;

int n;
long long P, Q, A[MAXN + 10];

int main() {
    scanf("%lld%lld%d", &P, &Q, &n);
    long long g = __gcd(P, Q);
    P /= g; Q /= g;

    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    __int128 p = A[n], q = 1;
    for (int i = n - 1; i > 0; i--) {
        __int128 pp = A[i] * p + q, qq = p;
        __int128 g = __gcd(pp, qq);
        p = pp / g; q = qq / g;
        if (p > INF || q > INF) { printf("NO\n"); return 0; }
    }

    if (p == P && q == Q) printf("YES\n");
    else printf("NO\n");
    return 0;
}
