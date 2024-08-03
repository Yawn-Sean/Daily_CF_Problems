bool check(vector<vector<int>> &edges, int x, int n) {
    vector<vector<int>> g(n+1);
    vector<int> dg(n+1);
    for(int i=0; i<x; i++) {
        g[edges[i][0]].push_back(edges[i][1]);
        dg[edges[i][1]] ++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i ++) if(dg[i] == 0) q.push(i);
    while(q.size()) {
        if(q.size() > 1) return 0;
        int t = q.front();
        q.pop();
        for(int x: g[t]){
            dg[x]--;
            if(dg[x] == 0) q.push(x);
        }
    }
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    int l=1, r=m;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check(edges, mid, n)) r = mid;
        else l = mid + 1;
    }

    if(check(edges, l, n)) cout << l << endl;
    else cout << -1 << endl;
}
