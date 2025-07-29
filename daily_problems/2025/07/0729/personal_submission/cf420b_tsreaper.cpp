#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, OP[MAXN + 5][2];

int last[MAXN + 5], len[MAXN + 5];
bool vis[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);

    int rem = 0;
    for (int i = 1; i <= m; i++) {
        char op[3]; scanf("%s", op);
        int x; scanf("%d", &x);
        if (!vis[x] && op[0] == '-') rem++;
        vis[x] = true;
        OP[i][0] = (op[0] == '+' ? 1 : 0);
        OP[i][1] = x;
    }

    int tot = (rem > 0 ? 1 : 0);
    for (int i = 1; i <= m; i++) {
        if (OP[i][0]) {
            last[OP[i][1]] = i;
            rem++;
        } else {
            len[OP[i][1]] += i - last[OP[i][1]];
            last[OP[i][1]] = 0;
            rem--;
        }
        if (rem > 0) tot++;
    }
    for (int i = 1; i <= n; i++) if (last[i] > 0) len[i] += m + 1 - last[i];

    vector<int> ans;
    for (int i = 1; i <= n; i++) if (!vis[i] || len[i] == tot) ans.push_back(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
    return 0;
}
