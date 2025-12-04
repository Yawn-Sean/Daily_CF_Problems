#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n;
char MAP[MAXN + 5][MAXN + 5];
vector<pii> ans;

bool vis[MAXN + 5];

void dfs(int sn) {
    vis[sn] = true;
    for (int fn = 1; fn <= n; fn++)
        if (MAP[sn][fn] != '0' && !vis[fn]) {
            dfs(fn);
            ans.push_back({sn, fn});
        }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    ans.clear();
    memset(vis, 0, sizeof(bool) * (n + 3));
    dfs(1);

    if (ans.size() == n - 1) {
        printf("Yes\n");
        for (pii p : ans) printf("%d %d\n", p.first, p.second);
    } else {
        printf("No\n");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
