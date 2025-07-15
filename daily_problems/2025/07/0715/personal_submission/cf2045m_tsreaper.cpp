#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

bool vis[MAXN + 5][MAXN + 5];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1}, mirror[2][4] = {1, 0, 3, 2, 3, 2, 1, 0};

bool check(int i, int j, int d) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) vis[i][j] = false;
    while (i >= 1 && i <= n && j >= 1 && j <= m) {
        vis[i][j] = true;
        if (MAP[i][j] == '/') d = mirror[0][d];
        else if (MAP[i][j] == '\\') d = mirror[1][d];
        i += dir[d][0];
        j += dir[d][1];
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] != '.' && !vis[i][j]) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    vector<string> ans;
    for (int j = 1; j <= m; j++) if (check(1, j, 2)) ans.push_back("N" + to_string(j));
    for (int i = 1; i <= n; i++) if (check(i, m, 3)) ans.push_back("E" + to_string(i));
    for (int j = 1; j <= m; j++) if (check(n, j, 0)) ans.push_back("S" + to_string(j));
    for (int i = 1; i <= n; i++) if (check(i, 1, 1)) ans.push_back("W" + to_string(i));

    printf("%d\n", ans.size());
    for (auto &s : ans) printf("%s ", s.c_str());
    printf("\n");
    return 0;
}
