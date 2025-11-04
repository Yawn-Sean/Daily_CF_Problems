#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, m, ans, A[MAXN + 5];

vector<int> e[MAXN + 5];
bool vis[MAXN + 5];
int root[MAXN + 5];

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
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return A[a] < A[b];
    });

    ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = false, root[j] = j;
        for (int j = i; j < n; j++) {
            int sn = ord[j];
            vis[sn] = true;
            for (int fn : e[sn]) if (vis[fn]) merge(sn, fn);
            if (findroot(1) == findroot(2)) { ans = min(ans, A[ord[j]] - A[ord[i]]); break; }
        }
    }
    printf("%d\n", ans);
    return 0;
}
