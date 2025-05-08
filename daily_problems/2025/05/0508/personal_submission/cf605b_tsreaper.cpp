#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, ans[MAXN + 5][2];

int main() {
    scanf("%d%d", &n, &m);
    vector<pii> vec[2];
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec[y].push_back({x, i});
    }
    for (int i = 0; i < 2; i++) sort(vec[i].begin(), vec[i].end(), greater<pii>());

    int lim = 1, x = 3, y = 0;
    while (!vec[0].empty() || !vec[1].empty()) {
        if (vec[0].empty() || (!vec[1].empty() && vec[1].back().first <= vec[0].back().first)) {
            pii p = vec[1].back(); vec[1].pop_back();
            ans[p.second][0] = lim;
            ans[p.second][1] = ++lim;
        } else {
            pii p = vec[0].back(); vec[0].pop_back();
            y++;
            if (y >= x - 1) x++, y = 1;
            if (x > lim) { printf("-1\n"); return 0; }
            ans[p.second][0] = x;
            ans[p.second][1] = y;
        }
    }

    for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}
