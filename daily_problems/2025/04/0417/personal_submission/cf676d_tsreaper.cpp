#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, SI, SJ, FI, FJ, MAP[MAXN + 5][MAXN + 5];
char s[MAXN + 5];

int dis[MAXN + 5][MAXN + 5][4];
short dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int getMsk(char c) {
    string chr = "+-|^><vLRUD*";
    int msk[] = {
        0b1111,
        0b1010,
        0b0101,
        0b0001,
        0b0010,
        0b1000,
        0b0100,
        0b0111,
        0b1101,
        0b1110,
        0b1011,
        0b0000
    };
    for (int i = 0; i < chr.size(); i++) if (c == chr[i]) return msk[i];
    assert(false);
}

bool check(int i, int j, int t, int k) {
    auto gao = [&](int x) {
        x <<= t;
        int y = x & 0b11110000;
        x &= 0b1111;
        x |= y >> 4;
        return x;
    };

    int ii = i + dir[k][0], jj = j + dir[k][1];
    int m1 = gao(MAP[i][j]), m2 = gao(MAP[ii][jj]);
    bool ret = (m1 >> k & 1) && (m2 >> ((k + 2) & 3) & 1);
    return ret;
}

int bfs() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int k = 0; k < 4; k++) dis[i][j][k] = -1;
    queue<array<int, 3>> q;
    q.push({SI, SJ, 0}); dis[SI][SJ][0] = 0;
    while (!q.empty()) {
        auto arr = q.front(); q.pop();
        int i = arr[0], j = arr[1], t = arr[2];
        if (i == FI && j == FJ) return dis[i][j][t];

        auto gao = [&](int ii, int jj, int tt) {
            if (dis[ii][jj][tt] >= 0) return;
            dis[ii][jj][tt] = dis[i][j][t] + 1;
            q.push({ii, jj, tt});
        };

        gao(i, j, (t + 1) & 3);
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m) continue;
            if (check(i, j, t, k)) gao(ii, jj, t);
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) MAP[i][j] = getMsk(s[j]);
    }
    scanf("%d%d%d%d", &SI, &SJ, &FI, &FJ);
    printf("%d\n", bfs());
    return 0;
}
