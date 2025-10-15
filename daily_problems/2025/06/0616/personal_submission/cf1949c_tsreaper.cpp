#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n;

vector<int> e[MAXN + 5];
int deg[MAXN + 5], sm[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    for (int i = 1; i <= n; i++) sm[i] = 1;
    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) pq.push({-1, i});
    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int sn = p.second;
        deg[sn] = 0;
        for (int fn : e[sn]) if (deg[fn] > 0) {
            if (sm[fn] < sm[sn]) continue;
            sm[fn] += sm[sn];
            if ((--deg[fn]) == 1) pq.push({-sm[fn], fn});
        }
    }

    bool ok = true;
    for (int i = 1; i <= n; i++) if (deg[i] > 0) ok = false;
    if (ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
