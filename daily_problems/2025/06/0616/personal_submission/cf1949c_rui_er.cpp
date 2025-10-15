const int N = 2e5 + 5;

int n, deg[N], val[N];
vector<int> e[N];
priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> heap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    rep(u, 1, n) val[u] = 1;
    rep(u, 1, n) if(deg[u] == 1) heap.emplace(val[u], u);
    while(!heap.empty()) {
        int u = get<1>(heap.top()); heap.pop();
        for(int v : e[u]) {
            if(!val[v]) continue;
            if(val[v] < val[u]) {
                cout << "NO" << endl;
                return 0;
            }
            val[v] += val[u];
            val[u] = 0;
            --deg[u]; --deg[v];
            if(deg[v] == 1) heap.emplace(val[v], v);
        }
    }
    cout << "YES" << endl;
    return 0;
}
