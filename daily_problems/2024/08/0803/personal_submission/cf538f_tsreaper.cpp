#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 10], ans[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 2; i <= n; i++) {
        int K = 1;
        while (K < n) {
            int t = (i - 2) / K;
            int R = (t == 0 ? n - 1 : (i - 2) / t);
            if (A[i] < A[t + 1]) ans[K]++, ans[R + 1]--;
            K = R + 1;
        }
    }

    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
        printf("%d%c", ans[i], "\n "[i + 1 < n]);
    }
    return 0;
}
