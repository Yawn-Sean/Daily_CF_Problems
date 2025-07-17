#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K;

vector<int> e[MAXN + 5];
int deg[MAXN + 5];

bool solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) e[i].clear(), deg[i] = 0;
    for (int i = 1; i <= K; i++) for (int j = 1, last; j <= n; j++) {
        int x; scanf("%d", &x);
        if (j > 2) {
            e[last].push_back(x);
            deg[x]++;
        }
        last = x;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        cnt++;
        for (int fn : e[sn]) if ((--deg[fn]) == 0) q.push(fn);
    }
    return cnt == n;
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--)
        if (solve()) printf("YES\n");
        else printf("NO\n");
    return 0;
}
