#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];

vector<int> e[MAXN + 5];

void dfs(int sn, int fa) {
    printf("%d ", sn);
    if (sn != 1) A[sn] = -A[sn];
    for (int fn : e[sn]) if (fn != fa) {
        dfs(fn, sn);
        printf("%d ", sn);
        A[sn] = -A[sn];
    }
    if (A[sn] == -1 && sn != 1) {
        printf("%d %d ", fa, sn);
        A[fa] = -A[fa];
        A[sn] = -A[sn];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs(1, 0);
    if (A[1] == -1) printf("%d 1 %d", e[1][0], e[1][0]);
    printf("\n");
    return 0;
}
