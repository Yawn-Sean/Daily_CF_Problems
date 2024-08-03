#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM ((int) 1e5)
using namespace std;

int n, m, A[MAXM + 10], B[MAXM + 10];

vector<int> e[MAXN + 10];
int deg[MAXN + 10];

bool check(int lim) {
    for (int i = 1; i <= n; i++) e[i].clear(), deg[i] = 0;
    for (int i = 1; i <= lim; i++) {
        e[A[i]].push_back(B[i]);
        deg[B[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
        if (q.size() > 1) return false;
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if ((--deg[fn]) == 0) q.push(fn);
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &A[i], &B[i]);
    if (check(m)) {
        int head = 1, tail = m;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (check(mid)) tail = mid;
            else head = mid + 1;
        }
        printf("%d\n", head);
    } else {
        printf("-1\n");
    }
    return 0;
}
