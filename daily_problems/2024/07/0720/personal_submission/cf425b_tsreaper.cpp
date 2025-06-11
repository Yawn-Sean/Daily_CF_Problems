#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
using namespace std;

int n, m, K, A[MAXN + 10][MAXM + 10];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &A[i][j]);
    int ans = K + 1;
    if (n <= K) {
        for (int msk = 0; msk < (1 << n); msk++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                int w[2] = {0};
                for (int i = 0; i < n; i++) w[msk >> i & 1 ^ A[i][j]]++;
                cnt += min(w[0], w[1]);
            }
            ans = min(ans, cnt);
        }
    } else {
        for (int ii = 0; ii < n; ii++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) if (i != ii) {
                int w[2] = {0};
                for (int j = 0; j < m; j++) w[A[i][j] ^ A[ii][j]]++;
                cnt += min(w[0], w[1]);
            }
            ans = min(ans, cnt);
        }
    }
    printf("%d\n", ans > K ? -1 : ans);
    return 0;
}