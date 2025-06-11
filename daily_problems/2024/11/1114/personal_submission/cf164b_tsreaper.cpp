#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m, ans, A[MAXN], B[MAXN];
int pA[MAXN + 1], pB[MAXN + 1];

int main() {
    scanf("%d%d", &n, &m);
    memset(pA, -1, sizeof(pA)); memset(pB, -1, sizeof(pB));
    for (int i = 0; i < n; i++) scanf("%d", &A[i]), pA[A[i]] = i;
    for (int i = 0; i < m; i++) scanf("%d", &B[i]), pB[B[i]] = i;

    if (n == 1) {
        if (pB[A[0]] >= 0) printf("1\n");
        else printf("0\n");
        return 0;
    }

    for (int i = 0, j = 0, now = 0, tot = 0; i < n; i++) if (pB[A[i]] >= 0) {
        if (now == 0) j = pB[A[i]], now = 1;
        while (true) {
            int nxt = pB[A[(i + now) % n]];
            if (nxt < 0) break;
            int dis = (nxt - j + m) % m;
            if (tot + dis >= m) break;
            j = nxt; now++; tot += dis;
        }
        ans = max(ans, now);
        now--;
        if (tot > 0) tot -= (pB[A[(i + 1) % n]] - pB[A[i]] + m) % m;
    }
    printf("%d\n", ans);
    return 0;
}
