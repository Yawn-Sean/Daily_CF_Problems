#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef pair<int, int> pii;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

vector<pii> pos[26];
char tmp[MAXN + 5][MAXN + 5];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    
    for (int c = 0; c < 26; c++) pos[c].clear();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (MAP[i][j] >= 'a' && MAP[i][j] <= 'z') pos[MAP[i][j] - 'a'].push_back({i, j});

    int mx = -1;
    array<int, 4> ans[26];
    for (int c = 0; c < 26; c++) if (!pos[c].empty()) {
        mx = c;
        int i1 = n + 1, j1 = m + 1, i2 = 0, j2 = 0;
        for (pii p : pos[c]) {
            i1 = min(i1, p.first);
            j1 = min(j1, p.second);
            i2 = max(i2, p.first);
            j2 = max(j2, p.second);
        }
        if (i1 == i2 || j1 == j2) {
            ans[c] = {i1, j1, i2, j2};
        } else {
            printf("NO\n");
            return;
        }
    }

    for (int c = 0; c <= mx; c++) if (pos[c].empty())
        ans[c] = {pos[mx][0].first, pos[mx][0].second, pos[mx][0].first, pos[mx][0].second};

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) tmp[i][j] = '.';
    for (char c = 0; c <= mx; c++) {
        for (int i = ans[c][0]; i <= ans[c][2]; i++) for (int j = ans[c][1]; j <= ans[c][3]; j++) tmp[i][j] = c + 'a';
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] != tmp[i][j]) { printf("NO\n"); return; }
    printf("YES\n%d\n", mx + 1);
    for (int c = 0; c <= mx; c++) for (int j = 0; j < 4; j++) printf("%d%c", ans[c][j], "\n "[j < 3]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
