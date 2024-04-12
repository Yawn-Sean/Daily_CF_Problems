#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

bool vis[MAXN + 10];

void solve() {
    int n, sx, sy; scanf("%d%d%d", &n, &sx, &sy);
    if (n < 0) exit(0);
    vector<int> vec[2];
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        int t = (x ^ y ^ sx ^ sy) & 1;
        vec[t].push_back(i);
    }

    int rem = n;
    auto gao = [&](int p) {
        for (int t : vec[p]) {
            if (vis[t]) continue;
            vis[t] = true;
            printf("%d\n", t); fflush(stdout);
            rem--;
            if (rem > 0) {
                int x; scanf("%d", &x);
                vis[x] = true; rem--;
            }
        }
    };

    memset(vis, 0, sizeof(bool) * (n + 3));
    if (vec[0].size() >= vec[1].size()) {
        printf("First\n"); fflush(stdout);
        gao(1); gao(0);
    } else {
        printf("Second\n"); fflush(stdout);
        int x; scanf("%d", &x);
        vis[x] = true; rem--;
        gao(0); gao(1);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
