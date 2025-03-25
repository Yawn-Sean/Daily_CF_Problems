#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K;
vector<int> ans[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];

void dfs(int sn, int fa, int col) {
    K = max(K, col);
    for (int i = 0, j = 1; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        while (j == col) j++;
        ans[j].push_back(v[sn][i]);
        dfs(fn, sn, j);
        j++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        e[y].push_back(x); v[y].push_back(i);
    }
    dfs(1, 0, 0);
    
    printf("%d\n", K);
    for (int i = 1; i <= K; i++) {
        printf("%d", ans[i].size());
        for (int x : ans[i]) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
