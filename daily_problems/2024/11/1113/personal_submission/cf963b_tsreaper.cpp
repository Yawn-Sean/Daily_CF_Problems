#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;
vector<int> ans;

vector<int> e[MAXN + 10];
int deg[MAXN + 10];

void dfs2(int sn, int fa) {
    ans.push_back(sn); deg[sn] = 0;
    for (int fn : e[sn]) if (fn != fa && deg[fn] > 0) dfs2(fn, sn);
}

void dfs1(int sn, int fa) {
    for (int fn : e[sn]) if (fn != fa) dfs1(fn, sn);
    if (deg[sn] % 2 == 0) dfs2(sn, fa), deg[fa]--;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x) {
            e[i].push_back(x); deg[i]++;
            e[x].push_back(i); deg[x]++;
        }
    }

    if (n % 2 == 0) { printf("NO\n"); return 0; }
    dfs1(1, 0);
    printf("YES\n");
    for (int x : ans) printf("%d\n", x);
    return 0;
}
