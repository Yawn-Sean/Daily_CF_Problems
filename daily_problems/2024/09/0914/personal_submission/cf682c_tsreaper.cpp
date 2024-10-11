#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;

int n, ans, A[MAXN + 10];

vector<int> e[MAXN + 10], v[MAXN + 10];

void dfs(int sn, long long d, long long mn) {
    if (d - A[sn] - mn > 0) return;
    ans++;
    mn = min(mn, d);
    for (int i = 0; i < e[sn].size(); i++) dfs(e[sn][i], d + v[sn][i], mn);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 2; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(i); v[x].push_back(y);
    }
    dfs(1, 0, INF);
    printf("%d\n", n - ans);
    return 0;
}
