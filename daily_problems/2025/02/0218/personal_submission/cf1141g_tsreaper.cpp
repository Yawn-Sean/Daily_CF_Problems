#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, ans[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int deg[MAXN + 5];

void dfs(int sn, int fa, int ban) {
    for (int i = 0, j = 1; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        if (deg[sn] > K) ans[v[sn][i]] = 1;
        else {
            while (j == ban) j++;
            ans[v[sn][i]] = j++;
        }
        dfs(fn, sn, ans[v[sn][i]]);
    }
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        e[y].push_back(x); v[y].push_back(i);
        deg[x]++; deg[y]++;
    }

    vector<int> vec;
    for (int i = 1; i <= n; i++) vec.push_back(deg[i]);
    sort(vec.begin(), vec.end());
    K = vec[n - 1 - K];

    dfs(1, 0, 0);
    printf("%d\n", K);
    for (int i = 1; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
