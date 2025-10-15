#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAGIC ((int) 1e3)
using namespace std;

int n, q, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    scanf("%d", &q);
    while (q--) {
        int op, i; scanf("%d%d", &op, &i);
        if (op == 1) scanf("%d", &A[i]);
        else {
            if (n - i > MAGIC) printf("%d\n", n);
            else if (i - 1 > MAGIC) printf("1\n");
            else {
                int ans = -1;
                for (int j = 1; j <= n; j++) {
                    int t = abs((i - j) * (i - j) * (i - j));
                    if (t >= A[j]) { ans = j; break; }
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
