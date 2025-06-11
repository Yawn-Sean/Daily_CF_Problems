#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, H, ans, L[MAXN + 10], R[MAXN + 10];

int main() {
    scanf("%d%d", &n, &H);
    for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]), R[i]--;
    for (int i = 1, j = 1, sm = 0; i <= n; i++) {
        sm += R[i] - L[i] + 1;
        while (j <= i && R[i] - L[j] + 1 - sm >= H) {
            sm -= R[j] - L[j] + 1;
            j++;
        }
        int rem = R[i] - L[j] + 1 - sm;
        rem = H - rem;
        ans = max(ans, R[i] - L[j] + 1 + rem);
    }
    printf("%d\n", ans);
    return 0;
}
