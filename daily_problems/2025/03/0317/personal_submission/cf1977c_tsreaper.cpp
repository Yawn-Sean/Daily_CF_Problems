#include <bits/stdc++.h>
#define MAXN 2000
#define MAXA ((long long) 1e9)
using namespace std;

int n, ans, A[MAXN + 5];

void gao(int goal) {
    long long l = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (goal % A[i] == 0) {
        l = l / gcd(l, A[i]) * A[i];
        cnt++;
    }
    for (int i = 1; i <= n; i++) if (l == A[i]) return;
    ans = max(ans, cnt);
}

void solve() {
    scanf("%d", &n);

    int mx = 0;
    long long l = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        mx = max(mx, A[i]);
        l = l / gcd(A[i], l) * A[i];
        l = min(l, MAXA + 10);
    }
    if (l != mx) { printf("%d\n", n); return; }

    ans = 0;
    for (int i = 1; i * i <= mx; i++) if (mx % i == 0) {
        gao(i);
        if (i * i != mx) gao(mx / i);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
