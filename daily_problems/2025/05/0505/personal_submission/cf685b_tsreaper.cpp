#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, q, pa[MAXN + 5], ans[MAXN + 5];

vector<int> e[MAXN + 5];
int f[MAXN + 5], g[MAXN + 5], dep[MAXN + 5];

void dfs(int sn, int d) {
    f[sn] = 1;
    dep[sn] = d;

    set<pii> st;
    st.insert({dep[sn], sn});
    for (int fn : e[sn]) {
        dfs(fn, d + 1);
        f[sn] += f[fn];
        g[sn] = max(g[sn], f[fn]);
        st.insert({dep[ans[fn]], ans[fn]});
    }

    while (true) {
        pii p = *prev(st.end());
        st.erase(p);
        if (g[p.second] * 2 <= f[sn] && (f[sn] - f[p.second]) * 2 <= f[sn]) {
            ans[sn] = p.second;
            break;
        }
        st.insert({dep[pa[p.second]], pa[p.second]});
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &pa[i]);
        e[pa[i]].push_back(i);
    }

    dfs(1, 1);
    while (q--) {
        int x; scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}
