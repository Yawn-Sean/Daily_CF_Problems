#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5], dis[MAXN + 5];

void bfs() {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    queue<int> q;
    q.push(1); dis[1] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();

        auto update = [&](int fn) {
            if (dis[fn] >= 0) return;
            q.push(fn);
            dis[fn] = dis[sn] + 1;
        };

        if (sn > 1) update(sn - 1);
        if (sn < n) update(sn + 1);
        update(A[sn]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    bfs();
    for (int i = 1; i <= n; i++) printf("%d%c", dis[i], "\n "[i < n]);
    return 0;
}
