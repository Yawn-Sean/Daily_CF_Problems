#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

int n, vis[MX];
vector<pair<int, char>> G[MX];
vector<int> part[3];

bool dfs(int v, int p, char c) {
    if (vis[v] != 0) {
        return vis[v] == p;
    }

    vis[v] = p;
    part[p].push_back(v);

    for (auto x : G[v]) {
        if (dfs(x.first, x.second == c ? p : p ^ 3, c) == false)
            return false;
    }

    return true;
}

vector<int> solve(char c) {
    memset(vis, 0, sizeof vis);

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (vis[i] == 0) {
            part[1].clear();
            part[2].clear();

            if (dfs(i, 1, c) == false) {
                for (int j = 0; j < n + 1; j++) ans.push_back(-1);

                return ans;
            }

            int f = 1;
            if (part[2].size() < part[1].size()) f = 2;

            ans.insert(ans.end(), part[f].begin(), part[f].end());
        }

    return ans;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        u--;
        v--;

        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    auto f = solve('R');
    auto g = solve('B');

    if (g.size() < f.size()) f = g;

    if (f.size() > n) {
        printf("-1\\n");

        return 0;
    }

    printf("%d\\n", (int)f.size());
    for (int x : f) printf("%d ", x + 1);
    printf("\\n");

    return 0;
}