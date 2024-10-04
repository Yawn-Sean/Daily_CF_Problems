#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 1000
using namespace std;

int n, m, ans[MAXN + MAXM + 10];
char MAP[MAXN + 10][MAXM + 10];

int root[MAXN + MAXM + 10], deg[MAXN + MAXM + 10];
vector<int> e[MAXN + MAXM + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x != y) root[x] = y;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n + m; i++) root[i] = i;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == '=') merge(i, j + n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int x = findroot(i), y = findroot(j + n);
        if (MAP[i][j] == '<') e[x].push_back(y), deg[y]++;
        else if (MAP[i][j] == '>') e[y].push_back(x), deg[x]++;
    }

    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n + m; i++) if (findroot(i) == i) {
        cnt++;
        if (deg[i] == 0) q.push(i), ans[i] = 1;
    }
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        cnt--;
        for (int fn : e[sn]) {
            ans[fn] = max(ans[fn], ans[sn] + 1);
            if ((--deg[fn]) == 0) q.push(fn);
        }
    }

    if (cnt > 0) printf("No\n");
    else {
        printf("Yes\n");
        for (int i = 1; i <= n + m; i++) ans[i] = ans[findroot(i)];
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
        for (int i = 1; i <= m; i++) printf("%d%c", ans[i + n], "\n "[i < m]);
    }
    return 0;
}
