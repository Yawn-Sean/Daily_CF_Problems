#include <bits/stdc++.h>
#define MAXK 50
#define MAXP 100
#define INF ((int) 1e9)
using namespace std;

int f[2][MAXK + 1][MAXP];

void update(int &a, int b) { a = max(a, b); }

int main() {
    int n, K, P; scanf("%d%d%d", &n, &K, &P);
    for (int k = 0; k <= K; k++) for (int c = 0; c < P; c++) f[0][k][c] = -INF;
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); x %= P;
        for (int k = 0; k <= K; k++) for (int c = 0; c < P; c++) f[i & 1][k][c] = -INF;
        for (int k = 0; k <= K; k++) for (int c = 0; c < P; c++) {
            if (k < K) update(f[i & 1][k + 1][x], f[i & 1 ^ 1][k][c] + c);
            if (k > 0) update(f[i & 1][k][(c + x) % P], f[i & 1 ^ 1][k][c]);
        }
    }
    int ans = 0;
    for (int c = 0; c < P; c++) ans = max(ans, f[n & 1][K][c] + c);
    printf("%d\n", ans);
    return 0;
}
