#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, ans[MAXN + 5], cnt[9];

vector<pii> vec[4][MAXN * 2 + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec[0][x].push_back({y, i});
        vec[1][y].push_back({x, i});
        vec[2][x + y].push_back({x, i});
        vec[3][x - y + n].push_back({x, i});
    }
    for (int i = 0; i < 4; i++) for (int j = 0; j <= n * 2; j++) {
        sort(vec[i][j].begin(), vec[i][j].end());
        for (int k = 0; k < vec[i][j].size(); k++) {
            if (k + 1 < vec[i][j].size()) ans[vec[i][j][k].second]++;
            if (k > 0) ans[vec[i][j][k].second]++;
        }
    }
    for (int i = 1; i <= m; i++) cnt[ans[i]]++;
    for (int i = 0; i <= 8; i++) printf("%d%c", cnt[i], "\n "[i < 8]);
    return 0;
}
