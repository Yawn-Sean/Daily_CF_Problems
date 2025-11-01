#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((int) 1e9)
using namespace std;

int n, ans, A[MAXN + 10];

vector<int> e[MAXN + 10];
int f[MAXN + 10];

int dfs(int sn) {
    f[sn] = A[sn];
    for (int fn : e[sn]) {
        int t = dfs(fn) + 1;
        ans = max(ans, t + f[sn]);
        f[sn] = max(f[sn], t);
    }
    return f[sn];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        e[x].push_back(i);
    }

    dfs(1);
    printf("%d\n", ans);
    return 0;
}
