int T;  
int n, fa[N];
vector<int> nodes[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        nodes[i].pb(i);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if (nodes[x].size() < nodes[y].size()) {
            fa[x] = y;
            for (auto v : nodes[x]) {
                nodes[y].pb(v);
            }
        } else {
            fa[y] = x;
            for (auto v : nodes[y]) {
                nodes[x].pb(v);
            }
        }
    }
    int root = find(1);
    for (int i = 0; i < n; i++) {
        cout << nodes[root][i] << " ";
    }
}