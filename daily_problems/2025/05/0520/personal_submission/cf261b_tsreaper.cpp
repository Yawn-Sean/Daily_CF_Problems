#include <bits/stdc++.h>
#define MAXN 50
#define MAXK 50
using namespace std;

int n, K, A[MAXN + 5];
double ans;

long long f[2][MAXN + 5][MAXK + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    scanf("%d", &K);

    int sm = 0;
    for (int i = 1; i <= n; i++) sm += A[i];
    if (sm <= K) { printf("%d\n", n); return 0; }

    for (int ban = 1; ban <= n; ban++) {
        for (int j = 0; j < n; j++) for (int k = 0; k <= K; k++) f[0][j][k] = 0;
        f[0][0][0] = 1;
        for (int i = 1; i <= n; i++) for (int j = 0; j < n; j++) for (int k = 0; k <= K; k++) {
            f[i & 1][j][k] = f[i & 1 ^ 1][j][k];
            if (i != ban && j > 0 && k >= A[i]) f[i & 1][j][k] += f[i & 1 ^ 1][j - 1][k - A[i]];
        }
        for (int j = 0; j < n; j++) for (int k = K - A[ban] + 1; k <= K; k++) {
            double tmp = j * f[n & 1][j][k];
            int u = 1;
            for (int t = 1; t <= j; t++) tmp *= 1.0 * t / (u++);
            for (int t = 1; t <= n - 1 - j; t++) tmp *= 1.0 * t / (u++);
            tmp /= n;
            ans += tmp;
        }
    }
    printf("%.12f\n", ans);
    return 0;
}
