#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5], T[MAXN + 5];
double ans, P[MAXN + 5];

double f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d%lf", &X[i], &Y[i], &T[i], &P[i]);

    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return T[a] < T[b];
    });

    for (int i = 1; i <= n; i++) {
        int u = ord[i - 1];
        f[i] = P[u];
        for (int j = 1; j < i; j++) {
            int v = ord[j - 1];
            int d2 = (X[u] - X[v]) * (X[u] - X[v]) + (Y[u] - Y[v]) * (Y[u] - Y[v]);
            long long t2 = 1LL * (T[u] - T[v]) * (T[u] - T[v]);
            if (d2 <= t2) f[i] = max(f[i], f[j] + P[u]);
        }
        ans = max(ans, f[i]);
    }
    printf("%.12f\n", ans);
    return 0;
}
