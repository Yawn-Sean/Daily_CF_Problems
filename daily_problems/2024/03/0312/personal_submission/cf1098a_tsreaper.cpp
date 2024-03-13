#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];
long long ans;

vector<int> e[MAXN + 10];

void dfs(int sn, int d) {
    int mn = 1e9;
    for (int fn : e[sn]) {
        dfs(fn, d + 1);
        mn = min(mn, A[fn]);
    }
    if (A[sn] == -1 && e[sn].size() > 0) A[sn] = mn;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        e[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    
    dfs(1, 1);
    ans = A[1];
    for (int sn = 1; sn <= n; sn++) for (int fn : e[sn]) if (A[fn] >= 0) {
        if (A[sn] > A[fn]) { printf("-1\n"); return 0; }
        ans += A[fn] - A[sn];
    }
    printf("%lld\n", ans);
    return 0;
}
