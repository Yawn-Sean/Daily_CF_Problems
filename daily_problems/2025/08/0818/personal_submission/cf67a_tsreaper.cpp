#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n;
char s[MAXN + 5];

vector<int> e[MAXN + 5];
int bcnt, bel[MAXN + 5], deg[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        if (s[i] != '=') {
            bcnt++;
            for (int k = j; k <= i; k++) bel[k] = bcnt;
            j = i + 1;
        }
    }

    for (int i = 1; i < n; i++) if (s[i] != '=') {
        int x, y;
        if (s[i] == 'L') x = bel[i + 1], y = bel[i];
        else x = bel[i], y = bel[i + 1];
        e[x].push_back(y); deg[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= bcnt; i++) if (deg[i] == 0) q.push(i), ans[i] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) {
            ans[fn] = max(ans[fn], ans[sn] + 1);
            if ((--deg[fn]) == 0) q.push(fn);
        }
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[bel[i]], "\n "[i < n]);
    return 0;
}
