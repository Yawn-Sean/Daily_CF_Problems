#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, X[MAXN + 5], Y[MAXN + 5];
long long dis[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);
    for (int i = 2; i <= n; i++) {
        X[i] -= X[1], Y[i] -= Y[1];
        dis[i] = 1LL * X[i] * X[i] + 1LL * Y[i] * Y[i];
    }

    vector<int> ord;
    for (int i = 2; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return dis[x] < dis[y];
    });

    int u = ord[0];
    for (int i = 1; i < ord.size(); i++) {
        int v = ord[i];
        long long cross = 1LL * X[u] * Y[v] - 1LL * X[v] * Y[u];
        if (cross != 0) { printf("1 %d %d\n", u, v); return 0; }
    }
    return 0;
}
