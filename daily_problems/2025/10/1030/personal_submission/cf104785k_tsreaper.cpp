#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, m;

vector<int> e[MAXN + 5], v[MAXN + 5];
vector<int> E[MAXN + 5], V[MAXN + 5];
int deg[MAXN + 5], used[MAXM + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        E[y].push_back(x); V[y].push_back(i);
        deg[y]++;
    }

    set<pii> st;
    for (int i = 1; i <= n; i++) st.insert({deg[i], i});

    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0)
        q.push(i), st.erase({0, i});
    while (true) {
        while (!q.empty()) {
            int sn = q.front(); q.pop();
            for (int i = 0; i < e[sn].size(); i++) {
                int fn = e[sn][i], idx = v[sn][i];
                if (used[idx]) continue;
                used[idx] = 1;
                int x = --deg[fn];
                st.erase({x + 1, fn});
                st.insert({x, fn});
                if (x == 0) q.push(fn), st.erase({0, fn});
            }
        }

        if (st.empty()) break;
        pii p = *(st.begin());

        deg[p.second] = 0;
        st.erase(st.begin());
        for (int t : V[p.second]) if (used[t] == 0) used[t] = -1;
        q.push(p.second);
    }

    vector<int> ans;
    for (int i = 1; i <= m; i++) if (used[i] == 1) ans.push_back(i);
    printf("YES\n%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
