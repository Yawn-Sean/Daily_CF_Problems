#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n;
long long X[MAXN + 10], Y[MAXN + 10], R[MAXN + 10];

vector<int> e[MAXN + 10];
int col[MAXN + 10];

bool bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 1;
    bool ok = true;
    int cnt = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        if (col[sn] == 1) cnt++;
        else cnt--;
        for (int fn : e[sn]) {
            if (col[fn]) {
                if (col[fn] == col[sn]) ok = false;
            } else {
                q.push(fn);
                col[fn] = 3 - col[sn];
            }
        }
    }
    return ok && cnt != 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &X[i], &Y[i], &R[i]);

    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        long long t = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
        if (t == (R[i] + R[j]) * (R[i] + R[j])) {
            e[i].push_back(j);
            e[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) if (!col[i] && bfs(i)) { printf("YES\n"); return 0; }
    printf("NO\n");
    return 0;
}
