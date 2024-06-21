#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN + 10];

vector<int> e[MAXN + 10];
int cnt[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++) if (A[i] == 0) q.push(i);
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        cnt[sn]++; ans.push_back(sn);
        for (int fn : e[sn]) {
            cnt[fn]++;
            if (cnt[fn] == A[fn]) q.push(fn);
        }
    }

    for (int i = 1; i <= n; i++) assert(cnt[i] != A[i]);
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
