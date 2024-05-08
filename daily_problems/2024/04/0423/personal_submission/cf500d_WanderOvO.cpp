/*

*/

int T;

void solve1() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        e[edges[i].u].pb({edges[i].v, edges[i].w});
        e[edges[i].v].pb({edges[i].u, edges[i].w});
        int u = edges[i].u, v = edges[i].v;
        if (u > v) {
            swap(u, v);
        }
        ids[{u, v}] = i;
    }
    
    dfs(1, 0);
    double res = 0;
    for (int i = 1; i < n; i++) {
        // cout << contrib[i] << "\n";
        res += edges[i].w * contrib[i];
    }
    cin >> q;
    while (q--) {
        LL id, new_w;
        cin >> id >> new_w;
        res -= edges[id].w * contrib[id];
        edges[id].w = new_w;
        res += edges[id].w * contrib[id];
        printf("%.10lf\n", res);
    }
}     