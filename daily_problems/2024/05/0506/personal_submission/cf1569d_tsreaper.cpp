#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, K, X[MAXN], Y[MAXN];
long long ans;

vector<int> R[MAXN], C[MAXN];

void gao(vector<int> *R, int n) {
    for (int idx = 0; idx < n; idx++) {
        auto &vec = R[idx];
        sort(vec.begin(), vec.end());
        for (int i = 0, j = 0; i < vec.size(); i++) {
            if (i + 1 == vec.size() || vec[i] != vec[i + 1]) {
                ans += 1LL * (i - j + 1) * j;
                j = i + 1;
            }
        }
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < n; i++) C[i].clear();
    for (int i = 0; i < m; i++) R[i].clear();

    for (int i = 0; i < n; i++) scanf("%d", &X[i]);
    for (int i = 0; i < m; i++) scanf("%d", &Y[i]);

    while (K--) {
        int x, y; scanf("%d%d", &x, &y);
        int ix = lower_bound(X, X + n, x) - X;
        int iy = lower_bound(Y, Y + m, y) - Y;
        if (X[ix] == x && Y[iy] == y) continue;
        if (X[ix] == x) R[iy].push_back(x);
        else C[ix].push_back(y);
    }

    ans = 0; gao(R, m); gao(C, n);
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
