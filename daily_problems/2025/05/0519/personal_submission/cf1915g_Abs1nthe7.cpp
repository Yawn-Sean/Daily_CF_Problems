#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e3 + 9;
int n, m;
vector<pair<int, int>> g[N];
vector<int> s;

void dij() 
{
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e18));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // 初始状态：时间=0，城市=1，当前最小s对应的城市=1
    dis[1][1] = 0;
    pq.push({0, 1, 1});

    while (!pq.empty()) 
    {
        auto [d, u, v] = pq.top();
        pq.pop();

        // 已存在更优路径，跳过
        if (d > dis[u][v]) continue;

        for (auto [y, dw] : g[u]) {
            int new_time = d + dw * s[v];
            int new_min_city = (s[y] < s[v]) ? y : v;

            if (new_time < dis[y][new_min_city]) {
                dis[y][new_min_city] = new_time;
                pq.push({new_time, y, new_min_city});
            }
        }
    }

    // 提取到达城市n的最小时间
    int ans = 1e18;
    for (int i = 1; i <= n; ++i) ans = min(ans, dis[n][i]);
    cout << ans << endl;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    s.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> s[i];
    dij();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) sol();
    return 0;
}
