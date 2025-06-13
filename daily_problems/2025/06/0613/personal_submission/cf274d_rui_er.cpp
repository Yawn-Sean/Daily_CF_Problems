const int N = 2e5 + 5;

int n, m, deg[N];
queue<int> q;
vector<int> e[N], ans;
vector<vector<int>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> a[i][j];
    int nds = m - 1;
    rep(i, 0, n - 1) {
        vector<int> buc;
        rep(j, 0, m - 1) if(a[i][j] != -1) buc.push_back(j);
        sort(buc.begin(), buc.end(), [&](int x, int y) {
            return a[i][x] < a[i][y];
        });
        int sz = buc.size(), l = 0, r = 0, vtx = -1;
        rep(j, 1, sz - 1){
            if(a[i][buc[j - 1]] == a[i][buc[j]]) ++r;
            else {
                if(vtx != -1) {
                    rep(u, l, r) {
                        e[vtx].push_back(buc[u]);
                        ++deg[buc[u]];
                    }
                }
                vtx = ++nds;
                rep(u, l, r) {
                    e[buc[u]].push_back(vtx);
                    ++deg[vtx];
                }
                l = r = j;
            }
        }
        if(vtx != -1) {
            rep(u, l, r) {
                e[vtx].push_back(buc[u]);
                ++deg[buc[u]];
            }
        }
    }
    rep(i, 0, nds) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u < m) ans.push_back(u);
        for(int v : e[u]) if(!--deg[v]) q.push(v);
    }
    if((int)ans.size() == m) rep(i, 0, m - 1) cout << ans[i] + 1 << " \n"[i == m - 1];
    else cout << -1 << endl;
    return 0;
}
