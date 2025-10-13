#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int t = n; t > 0; t--) {
        bool ok = false;
        for (int i = t; i > 0; i--) {
            if (i < A[i]) { printf("NO\n"); return 0; }
            if (i == A[i]) {
                ans[t] = i;
                for (int j = i; j < t; j++) A[j] = A[j + 1];
                ok = true;
                break;
            }
        }
        if (!ok) { printf("NO\n"); return 0; }
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
