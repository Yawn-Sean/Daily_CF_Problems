#include <bits/stdc++.h>
#define MAXX 15
using namespace std;

long long L;
bool vis[MAXX + 5];

unordered_set<long long> st[MAXX + 5];

void dfs(int d, long long now) {
    if (d > MAXX) {
        if (now <= L && now > 0) st[d].insert(now);
        return;
    }

    if (st[d].count(now)) return;
    st[d].insert(now);
    dfs(d + 1, now);
    if (!vis[d]) return;
    for (int i = 1; now <= L; now = now * (d + 1) + d) dfs(d + 1, now);
}

int main() {
    int n; scanf("%d%lld", &n, &L);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vis[x] = true;
    }
    dfs(2, 0);
    printf("%d\n", st[MAXX + 1].size());
    return 0;
}
