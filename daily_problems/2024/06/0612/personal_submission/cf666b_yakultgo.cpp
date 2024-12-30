#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int to, next;
} e[100005];
const int N = 3005;
int dis[N][N];
bool vis[N];
struct Dis {
    int dis, id;
} dis1[N][N], dis2[N][N];
vector<int> adj[N];
int ans = 0, ansa, ansb, ansc, ansd;
bool cmp(Dis x, Dis y) {
    return x.dis > y.dis;
}
void bfs(int s) {
    queue<int> q;
    q.push(s);
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    dis[s][s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dis[s][v] = dis[s][u] + 1;
                q.push(v);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dis1[i][j].dis = dis[i][j], dis1[i][j].id = j;
        sort(dis1[i] + 1, dis1[i] + n + 1, cmp);
        for (int j = 1; j <= n; j++) dis2[i][j].dis = dis[j][i], dis2[i][j].id = j;
        sort(dis2[i] + 1, dis2[i] + n + 1, cmp);
    }
    for (int b = 1; b <= n; b++) {
        for (int c = 1; c <= n; c++) {
            if (b == c) continue;
            for (int x = 1; x <= 4; x++)
                for (int y = 1; y <= 4; y++) {
                    int a = dis2[b][x].id, d = dis1[c][y].id;
                    if (!dis[a][b] || !dis[b][c] || !dis[c][d]) continue;
                    if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
                    int now = dis[a][b] + dis[b][c] + dis[c][d];
                    if (ans < now) ans = now, ansa = a, ansb = b, ansc = c, ansd = d;
                }
        }
    }
    cout << ansa << " " << ansb << " " << ansc << " " << ansd << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}