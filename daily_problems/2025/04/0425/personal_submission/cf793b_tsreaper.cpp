#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

int dis[MAXN + 5][MAXN + 5][4];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

bool bfs() {
    int SI, SJ;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 'S') SI = i, SJ = j;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int k = 0; k < 4; k++) dis[i][j][k] = -1;
    deque<array<int, 4>> dq;
    for (int k = 0; k < 4; k++) dq.push_back({SI, SJ, k, 0});
    while (!dq.empty()) {
        auto arr = dq.front(); dq.pop_front();
        int i = arr[0], j = arr[1], k = arr[2];
        if (dis[i][j][k] >= 0) continue;
        dis[i][j][k] = arr[3];
        if (MAP[i][j] == 'T') {
            if (arr[3] <= 2) return true;
            else return false;
        }
        for (int kk = 0; kk < 4; kk++) {
            int ii = i + dir[kk][0], jj = j + dir[kk][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == '*') continue;
            if (k == kk) dq.push_front({ii, jj, kk, arr[3]});
            else dq.push_back({ii, jj, kk, arr[3] + 1});
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    if (bfs()) printf("YES\n");
    else printf("NO\n");
    return 0;
}
