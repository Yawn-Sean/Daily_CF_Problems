#include <bits/stdc++.h>
#define MAXPROD ((int) 1e5)
using namespace std;

int n, m, A[MAXPROD];

vector<int> e[MAXPROD * 3 + 5];
int tot, deg[MAXPROD * 3 + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, idx = 0; i < n; i++) for (int j = 0; j < m; j++, idx++) scanf("%d", &A[idx]);

    tot = m;
    for (int i = 0; i < n; i++) {
        map<int, vector<int>> mp;
        for (int j = 0; j < m; j++) {
            int x = A[i * m + j];
            if (x >= 0) mp[x].push_back(j + 1);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            for (int x : it->second) {
                e[tot + 1].push_back(x); deg[x]++;
                e[x].push_back(tot + 2); deg[tot + 2]++;
            }
            if (it != mp.begin()) e[tot].push_back(tot + 1), deg[tot + 1]++;
            tot += 2;
        }
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= tot; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        if (sn <= m) ans.push_back(sn);
        for (int fn : e[sn]) if ((--deg[fn]) == 0) q.push(fn);
    }
    if (ans.size() < m) printf("-1\n");
    else for (int i = 0; i < m; i++) printf("%d%c", ans[i], "\n "[i + 1 < m]);
    return 0;
}
