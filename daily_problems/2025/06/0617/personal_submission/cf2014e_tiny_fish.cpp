#include <bits/stdc++.h>

#define int long long

using std::cin, std::cout, std::ios;

int solve() {
    int n, m, h; cin >> n >> m >> h;
    std::vector <bool> horse(n);
    for(int i = 0, x; i < h; i++) cin >> x, horse[x - 1] = true;
    std::vector e(n, std::vector < std::pair <int, int> > ());
    for(int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; u --, v --;
        e[u].emplace_back(v, w), e[v].emplace_back(u, w);
    }
    
    std::priority_queue < std::tuple <int, bool, int> > q; 
    
    std::vector vis(n, std::vector <bool> (2));
    std::vector dis(2, std::vector <int> (2*n, 1e18));
    
    q.emplace(0, horse[0], 0);

    dis[0][0] = 0;
    if(horse[0]) dis[0][n] = 0;

    while(!q.empty()) {
        auto [d, f, u] = q.top(); d *= -1; q.pop();
        // cout << d << ' ' << f << ' ' << u << '\n';
        if(vis[u][f]) continue;
        vis[u][f] = true;
        for(auto &[v, w] : e[u]) {
            if(f or horse[u]) {
                if(d + w / 2 < dis[0][n+v]) {
                    dis[0][n+v] = d + w / 2;
                    q.emplace(-dis[0][n+v], true, v);
                }
            } else {
                if(d + w < dis[0][v]) {
                    dis[0][v] = d + w;
                    q.emplace(-dis[0][v], false, v);
                }
            }
        }
    }

    vis.assign(n, std::vector <bool> (2, false));
    q.emplace(0, horse[n-1], n-1); 
    
    dis[1][n-1] = 0;
    if(horse[n-1]) dis[1][2*n-1] = 0;

    while(!q.empty()) {
        auto [d, f, u] = q.top(); d *= -1; q.pop();
        if(vis[u][f]) continue;
        vis[u][f] = true;
        for(auto &[v, w] : e[u]) {
            if(f or horse[u]) {
                if(d + w / 2 < dis[1][n+v]) {
                    dis[1][n+v] = d + w / 2;
                    q.emplace(-dis[1][n+v], true, v);
                }
            } else {
                if(d + w < dis[1][v]) {
                    dis[1][v] = d + w;
                    q.emplace(-dis[1][v], false, v);
                }
            }
        }
    }

    int ans = 1e18;

    for(int i = 0; i < n; i++) {
        // cout << i << ' ' << dis[0][i] << ' ' << dis[1][i] << ' ' << dis[0][i+n] << ' ' << dis[1][i+n] << '\n';
        ans = std::min(ans, std::max(std::min(dis[0][i], dis[0][i+n]), std::min(dis[1][i], dis[1][i+n])));
    }

    return ans == 1e18 ? -1 : ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int _; cin >> _; while(_--) cout << solve() << '\n';
    return 0;
}