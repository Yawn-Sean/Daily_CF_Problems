#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
vector<int> e[MAXN + 10];

int f[MAXN + 10];

int dfs(int sn) {
    if (e[sn].size() == 0) return f[sn] = 1;
    for (int fn : e[sn]) f[sn] += dfs(fn);
    return f[sn];
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        e[x].push_back(i);
    }

    dfs(1);
    sort(f + 1, f + n + 1);
    for (int i = 1; i <= n; i++) printf("%d%c", f[i], "\n "[i < n]);
    return 0;
}
