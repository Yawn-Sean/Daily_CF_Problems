#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define INF ((int) 2e9)
using namespace std;

int n, K, A[MAXN + 10];

int f[MAXN + 10], g[MAXN + 10];

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) A[i] = INF;
    vector<int> pos;
    for (int i = 0; i < K; i++) {
        int x; scanf("%d", &x);
        pos.push_back(x);
    }
    for (int i = 0; i < K; i++) {
        int x; scanf("%d", &x);
        A[pos[i]] = x;
    }

    int now = INF;
    for (int i = 1; i <= n; i++) {
        now = min(now + 1, A[i]);
        f[i] = now;
    }

    now = INF;
    for (int i = n; i > 0; i--) {
        now = min(now + 1, A[i]);
        g[i] = now;
    }

    for (int i = 1; i <= n; i++) printf("%d%c", min(f[i], g[i]), "\n "[i < n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
