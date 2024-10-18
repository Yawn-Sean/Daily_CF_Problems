#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200003;
int colors[N];
char comment[9];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        map<int, map<int, int>> g;
        bool conflict = false;
        for (int i = 0, u, v; i < m; i++) {
            scanf("%d%d%s", &u, &v, comment);
            int w = strcmp(comment, "crewmate") == 0 ? 0 : 1;
            auto it = g[u].find(v);
            if (it != g[u].end()) {
                if (w != it->second) {
                    conflict = true;
                }
            } else {
                g[u].emplace(v, w);
                g[v].emplace(u, w);
            }
        }
        if (conflict) {
            printf("-1\n");
            continue;
        }
        memset(colors, -1, sizeof(colors));
        int cnt[2]{};
        function<bool(int, int, int)> dfs = [&] (int u, int p, int c) -> bool {
            if (colors[u] != -1) return colors[u] == c;
            colors[u] = c;
            cnt[c]++;
            for (auto& [v, w] : g[u]) {
                if (v != p) {
                    if (!dfs(v, u, c ^ w)) return false;
                }
            }
            return true;
        };
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cnt[0] = 0, cnt[1] = 0;
            if (colors[i] == -1 && !dfs(i, 0, 0)) {
                conflict = true;
                break;
            }
            ans += max(cnt[0], cnt[1]);
        }
        if (conflict) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}

