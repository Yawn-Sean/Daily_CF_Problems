#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

const int N = 3010, M = 5010, inf = 0x3f3f3f3f;
int h[N], e[M], ne[M], ind;
int dist[N][N];

void add(int a, int b) {
    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
    return;
}

void bfs(int root) { 
    dist[root][root] = 0;
    queue<int> q;
    q.push(root);
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[root][j] > dist[root][t] + 1) {
                dist[root][j] = dist[root][t] + 1;
                q.push(j);
            }
        }
    }
    return;
}


void solve() {
    int n, m; cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < m; i++) { 
        int a, b; cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    vector<PII> vec1[n + 1], vec2[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == inf) continue;
            vec1[j].emplace_back(dist[i][j], i);
            vec2[i].emplace_back(dist[i][j], j);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(vec1[i].rbegin(), vec1[i].rend());
        sort(vec2[i].rbegin(), vec2[i].rend());
    }
    int ans = 0;
    vector<int> out;
    for (int b = 1; b <= n; b++) {
        for (int c = 1; c <= n; c++) {
            if (b == c || dist[b][c] == inf) continue;
            for (int i = 0; i < min(3, (int)vec1[b].size()); i++) {
                int a = vec1[b][i].second;
                if (a == b || a == c || dist[a][b] == inf) continue;
                for (int j = 0; j < min(3, (int)vec2[c].size()); j++) {
                    int d = vec2[c][j].second;
                    if (d == a || d == b || d == c || dist[b][d] == inf) continue;
                    int cnt = dist[a][b] + dist[b][c] + dist[c][d];
                    if (cnt > ans) { 
                        ans = cnt;
                        out = {a, b, c, d};
                    }
                }
            }
        }
    }
    for (auto &x : out) cout << x << " ";
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
