#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5], goal[MAXN + 5][MAXN + 5];
vector<array<int, 4>> ans;

void change(int i, int j) {
    if (MAP[i][j] == '.') MAP[i][j] = '#';
    else MAP[i][j] = '.';
}

void mov(int i, int j, int ii, int jj, int I, int J) {
    while (true) {
        ans.push_back({i, j, ii, jj});
        change(i, j); change(ii, jj);
        if (i == I && j == J) break;
        ii = i; jj = j;
        if (j < J) {
            if (i > I + 1) i--;
            else j++;
        } else {
            if (i > I) i--;
            else j--;
        }
    }
}

bool gao(int I, int J) {
    if (MAP[I][J] == goal[I][J]) return true;
    for (int i = I; i <= n; i++) for (int j = J; j <= m; j++) {
        if (j + 1 <= m && MAP[i][j] == MAP[i][j + 1]) { mov(i, j, i, j + 1, I, J); return true; }
        if (i + 1 <= n && MAP[i][j] == MAP[i + 1][j]) { mov(i, j, i + 1, j, I, J); return true; }
    }
    for (int i = I + 1; i <= n; i++) for (int j = J; j > 0; j--) {
        if (j - 1 >= 1 && MAP[i][j] == MAP[i][j - 1]) { mov(i, j, i, j - 1, I, J); return true; }
        if (i + 1 <= n && MAP[i][j] == MAP[i + 1][j]) { mov(i, j, i + 1, j, I, J); return true; }
    }
    return false;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int i = 1; i <= n; i++) scanf("%s", goal[i] + 1);

    ans.clear();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (!gao(i, j)) { printf("-1\n"); return; }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) assert(MAP[i][j] == goal[i][j]);
    printf("%d\n", ans.size());
    for (auto &arr : ans) for (int i = 0; i < 4; i++) printf("%d%c", arr[i], "\n "[i < 3]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
