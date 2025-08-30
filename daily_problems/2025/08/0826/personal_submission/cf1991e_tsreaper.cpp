#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
using namespace std;

int n, m;

vector<int> e[MAXN + 10];
int col[MAXN + 10];

bool bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) {
            if (col[fn]) {
                if (col[fn] == col[sn]) return false;
            } else {
                q.push(fn); col[fn] = 3 - col[sn];
            }
        }
    }
    return true;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    memset(col, 0, sizeof(int) * (n + 3));
    if (bfs(1)) {
        printf("Bob\n"); fflush(stdout);
        vector<int> vec[2];
        for (int i = 1; i <= n; i++) vec[col[i] - 1].push_back(i);
        for (int i = 1; i <= n; i++) {
            int x, y; scanf("%d%d", &x, &y);
            if ((x == 1 || y == 1) && vec[0].size() > 0) {
                printf("%d 1\n", vec[0].back()); fflush(stdout);
                vec[0].pop_back();
            } else if ((x == 2 || y == 2) && vec[1].size() > 0) {
                printf("%d 2\n", vec[1].back()); fflush(stdout);
                vec[1].pop_back();
            } else {
                assert(x == 3 || y == 3);
                if (vec[0].size() > 0) {
                    printf("%d 3\n", vec[0].back()); fflush(stdout);
                    vec[0].pop_back();
                } else {
                    printf("%d 3\n", vec[1].back()); fflush(stdout);
                    vec[1].pop_back();
                }
            }
        }
    } else {
        printf("Alice\n"); fflush(stdout);
        for (int i = 1; i <= n; i++) {
            printf("1 2\n"); fflush(stdout);
            scanf("%*d%*d");
        }
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
