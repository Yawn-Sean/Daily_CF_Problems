#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];

void solve() {
    scanf("%d", &n);
    long long sm = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        sm += A[i];
        mx = max(mx, A[i]);
    }

    if (mx < 2) {
        printf("0\n");
    } else if (sm == 3 && mx == 3) {
        printf("1\n");
    } else if (n == 2) {
        if (A[1] < A[2]) swap(A[1], A[2]);
        int t = (A[1] - A[2]) / 3;
        A[1] -= t * 2;
        A[2] += t;

        long long ans = t;
        int det = A[1] - A[2];
        if (det == 0) {
            ans += (A[1] - 1) * 2;
        } else {
            ans += min(A[1], A[2]) * 2;
            if (det > 1) ans++;
        }
        printf("%d\n", ans);
    } else {
        printf("%lld\n", sm - 1);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
