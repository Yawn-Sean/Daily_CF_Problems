const int N = 2005;

int T, n, m, deg[N], vis[N], tms;
vector<int> e[N], cyc;

bool dfs(int u, int s, int t) {
    cyc.push_back(u);
    vis[u] = tms;
    if(u == t) return true;
    for(int v : e[u]) {
        if(abs(vis[v]) != tms && (s != u || v != t)) {
            if(dfs(v, s, t)) {
                return true;
            }
        }
    }
    cyc.pop_back();
    vis[u] = -tms;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> m;
        rep(i, 1, m) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            ++deg[u]; ++deg[v];
        }
        bool ok = false;
        rep(u, 1, n) {
            if(deg[u] >= 4 && !ok) {
                for(int v : e[u]) {
                    cyc.clear();
                    ++tms;
                    if(dfs(u, u, v)) {
                        vector<tuple<int, int>> vec;
                        for(int w : e[u]) {
                            if(vis[w] != tms) {
                                vec.emplace_back(u, w);
                                if((int)vec.size() >= 2) break;
                            }
                        }
                        if((int)vec.size() < 2) continue;
                        int sz = (int)cyc.size();
                        rep(i, 0, sz - 1) vec.emplace_back(cyc[i], cyc[(i + 1) % sz]);
                        cout << "Yes" << endl << (int)vec.size() << endl;
                        for(auto [u, v] : vec) cout << u << " " << v << endl;
                        ok = true;
                        break;
                    }
                }
            }
        }
        if(!ok) cout << "No" << endl;
        // clear
        rep(i, 1, n) {
            deg[i] = 0;
            e[i].clear();
        }
    }
    return 0;
}
