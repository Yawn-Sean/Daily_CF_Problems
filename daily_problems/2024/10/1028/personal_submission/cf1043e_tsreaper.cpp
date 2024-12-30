#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, m, X[MAXN + 10], Y[MAXN + 10];
long long ans[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return X[a] - Y[a] < X[b] - Y[b];
    });

    long long smX = 0, smY = 0;
    for (int i = 1; i <= n; i++) smY += Y[i];
    for (int i = 0; i < n; i++) {
        int idx = ord[i];
        smY -= Y[idx];
        ans[idx] = 1LL * X[idx] * (n - 1 - i) + 1LL * Y[idx] * i + smX + smY;
        smX += X[idx];
    }
    while (m--) {
        int a, b; scanf("%d%d", &a, &b);
        int t = min(X[a] + Y[b], X[b] + Y[a]);
        ans[a] -= t; ans[b] -= t;
    }
    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], "\n "[i < n]);
    return 0;
}
