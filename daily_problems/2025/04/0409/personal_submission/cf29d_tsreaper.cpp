#include <bits/stdc++.h>
#define MAXN 300
using namespace std;

int n;
vector<int> ans;

vector<int> e[MAXN + 5];
int m, pa[MAXN + 5], dep[MAXN + 5];

void dfs(int sn, int fa, int d) {
    pa[sn] = fa;
    dep[sn] = d;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs(1, 0, 0);
    for (int i = 2; i <= n; i++) if (e[i].size() == 1) m++;
    vector<int> leaves;
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        leaves.push_back(x);
    }
    leaves.push_back(1);

    ans.push_back(1);
    for (int i = 0, y = 1; i <= m; i++) {
        int x = leaves[i];
        vector<int> X, Y;
        while (x != y) {
            if (dep[x] > dep[y]) X.push_back(x), x = pa[x];
            else Y.push_back(y), y = pa[y];
            if (ans.size() + X.size() + Y.size() > 2 * n - 1) { printf("-1\n"); return 0; }
        }
        ans.pop_back();
        for (int t : Y) ans.push_back(t);
        ans.push_back(x);
        reverse(X.begin(), X.end());
        for (int t : X) ans.push_back(t);
        y = leaves[i];
    }
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
