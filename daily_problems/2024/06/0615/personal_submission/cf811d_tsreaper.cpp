#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
using namespace std;
typedef pair<int, int> pii;

int n, m;
char MAP[MAXN + 10][MAXM + 10];

int dis[MAXN + 10][MAXM + 10];
short dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    int FI, FJ;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (MAP[i][j] == 'F') FI = i, FJ = j;

    bool flag[2] = {0};
    int r, c;
    if (m > 1 && MAP[1][2] == '.') {
        printf("R\n"); fflush(stdout);
        scanf("%d%d", &r, &c);
        if (c == 1) flag[1] = true;

        if (FI == 1) {
            while (c < FJ) {
                printf("%c\n", flag[1] ? 'L' : 'R'); fflush(stdout);
                scanf("%d%d", &r, &c);
            }
            return 0;
        }

        if (c == 2) {
            printf("%c\n", flag[1] ? 'R' : 'L'); fflush(stdout);
            scanf("%d%d", &r, &c);
        }
        while (MAP[r + 1][c] == '*') {
            printf("%c\n", flag[1] ? 'L' : 'R'); fflush(stdout);
            scanf("%d%d", &r, &c);
        }
        printf("D\n"); fflush(stdout);
        scanf("%d%d", &r, &c);
        if (r == 1) flag[0] = true;
    } else {
        printf("D\n"); fflush(stdout);
        scanf("%d%d", &r, &c);
        if (r == 1) flag[0] = true;

        if (FJ == 1) {
            while (r < FI) {
                printf("%c\n", flag[0] ? 'U' : 'D'); fflush(stdout);
                scanf("%d%d", &r, &c);
            }
            return 0;
        }

        if (r == 2) {
            printf("%c\n", flag[0] ? 'D' : 'U'); fflush(stdout);
            scanf("%d%d", &r, &c);
        }
        while (MAP[r][c + 1] == '*') {
            printf("%c\n", flag[0] ? 'U' : 'D'); fflush(stdout);
            scanf("%d%d", &r, &c);
        }
        printf("R\n"); fflush(stdout);
        scanf("%d%d", &r, &c);
        if (c == 1) flag[1] = true;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j] = -1;
    queue<pii> q;
    q.push({FI, FJ}); dis[FI][FJ] = 0;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || ii > n || jj <= 0 || jj > m || MAP[ii][jj] == '*') continue;
            if (dis[ii][jj] >= 0) continue;
            q.push({ii, jj}); dis[ii][jj] = dis[i][j] + 1;
        }
    }

    while (dis[r][c] > 0) {
        for (int k = 0; k < 4; k++) {
            int rr = r + dir[k][0], cc = c + dir[k][1];
            if (rr > 0 && rr <= n && cc > 0 && cc <= m && dis[rr][cc] == dis[r][c] - 1) {
                if (k == 0) printf("%c\n", flag[0] ? 'D' : 'U');
                else if (k == 1) printf("%c\n", flag[0] ? 'U' : 'D');
                else if (k == 2) printf("%c\n", flag[1] ? 'R' : 'L');
                else printf("%c\n", flag[1] ? 'L' : 'R');
                fflush(stdout);
                scanf("%d%d", &r, &c);
                break;
            }
        }
    }
    return 0;
}
