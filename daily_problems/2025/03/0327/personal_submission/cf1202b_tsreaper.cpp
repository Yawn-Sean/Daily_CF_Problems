#include <bits/stdc++.h>
#define MAXN ((int) 2e6)
using namespace std;
typedef pair<int, int> pii;

int n, ans[10][10];
char s[MAXN + 5];

int f[10][10][10][10];

void bfs(int x, int y, int S) {
    queue<pii> q;
    q.push({S, 0});
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int now = p.first, d = p.second;
        auto add = [&](int nxt) {
            if (f[x][y][S][nxt] >= 0) return;
            q.push({nxt, d + 1}); f[x][y][S][nxt] = d + 1;
        };
        add((now + x) % 10); add((now + y) % 10);
    }
}

int main() {
    memset(f, -1, sizeof(f));
    for (int i = 0; i < 10; i++) for (int j = i; j < 10; j++)
        for (int k = 0; k < 10; k++) bfs(i, j, k);

    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 0; i < 10; i++) for (int j = i; j < 10; j++) {
        for (int k = 1; k < n; k++) {
            int t = f[i][j][s[k] - '0'][s[k + 1] - '0'];
            if (t < 0) { ans[i][j] = -1; break; }
            ans[i][j] += t - 1;
        }
    }
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) printf("%d%c", ans[min(i, j)][max(i, j)], "\n "[j < 9]);
    return 0;
}
