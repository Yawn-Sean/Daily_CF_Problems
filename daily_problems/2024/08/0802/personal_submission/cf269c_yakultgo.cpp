#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 5;

struct node {
    int t, c, id;
};

int n, m, deg[N], ans[N];
vector<node> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c, i});
        g[b].push_back({a, c, i + m});
        deg[a] += c;
        deg[b] += c;
    }
    for (int i = 1; i <= n - 1; i++) {
        deg[i] /= 2;
    }
    deg[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto p : g[x]) {
            int y = p.t, c = p.c, id = p.id;
            if (deg[y] == 0) {
                continue;
            }
            ans[(id > m ? (id - m) : id)] = (id > m);
            deg[y] -= c;
            if (deg[y] == 0) {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}