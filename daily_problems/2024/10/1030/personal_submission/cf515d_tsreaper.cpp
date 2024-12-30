#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, m;
char MAP[MAXN + 10][MAXN + 10];

vector<int> e[MAXN * MAXN + 10];
short deg[MAXN * MAXN + 10];
bool vis[MAXN * MAXN + 10];

int head, tail, q[MAXN * MAXN + 10];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", MAP[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (MAP[i][j] == '.') {
        cnt++;
        int sn = i * m + j;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii < 0 || jj < 0 || ii >= n || jj >= m || MAP[ii][jj] != '.') continue;
            int fn = ii * m + jj;
            e[sn].push_back(fn); deg[fn]++;
        }
    }

    head = tail = 1;
    for (int i = 0; i < n * m; i++) if (deg[i] == 1) q[tail++] = i;
    while (head < tail) {
        int sn = q[head++];
        if (deg[sn] == 0) continue;
        int i = sn / m, j = sn % m;
        cnt--; deg[sn] = 0; vis[sn] = true;
        for (int fn : e[sn]) if (!vis[fn]) {
            int ii = fn / m, jj = fn % m;
            if (jj == j + 1) MAP[i][j] = '<', MAP[ii][jj] = '>';
            else if (jj == j - 1) MAP[i][j] = '>', MAP[ii][jj] = '<';
            else if (ii == i + 1) MAP[i][j] = '^', MAP[ii][jj] = 'v';
            else MAP[i][j] = 'v', MAP[ii][jj] = '^';
            cnt--; deg[fn] = 0; vis[fn] = true;
            for (int x : e[fn]) if (!vis[x]) {
                deg[x]--;
                if (deg[x] == 1) q[tail++] = x;
            }
            break;
        }
    }

    if (cnt > 0) printf("Not unique\n");
    else for (int i = 0; i < n; i++) printf("%s\n", MAP[i]);
    return 0;
}
