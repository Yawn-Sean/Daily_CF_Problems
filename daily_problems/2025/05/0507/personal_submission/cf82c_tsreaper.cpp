#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int pa[MAXN + 5], cap[MAXN + 5], used[MAXN + 5], pos[MAXN + 5];

void dfs(int sn, int fa) {
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        pa[fn] = sn;
        cap[fn] = v[sn][i];
        dfs(fn, sn);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    vector<int> ord;
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return A[a] < A[b];
    });

    dfs(1, 0);
    for (int i = 1; i <= n; i++) pos[i] = i;
    while (true) {
        bool done = true;
        for (int i = 1; i <= n; i++) used[i] = 0;
        for (int x : ord) if (pos[x] > 1) {
            done = false;
            ans[x]++;
            if (used[pos[x]] < cap[pos[x]]) {
                used[pos[x]]++;
                pos[x] = pa[pos[x]];
            }
        }
        if (done) break;
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
