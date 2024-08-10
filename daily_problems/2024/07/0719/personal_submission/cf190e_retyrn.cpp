const int N = 5e5+10, M = 1e6+10;
int n, m, idx;
int e[M << 1], ne[M << 1], h[N], cnt[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void solve() {
    mem(h, -1);
    cin >> n >> m;
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        add(x, y);
        add(y, x);
        cnt[x] += 1;
        cnt[y] += 1;
    }
    
    int mn = inf, ver = -1;
    for (int i = 0; i < n; i ++) {
        if (cnt[i] < mn) {
            mn = cnt[i];
            ver = i;
        }
    }
    // 融合出一个新点
    vector<bool> with_ver(n, true);
    for (int i = h[ver]; ~i; i = ne[i]) {
        int j = e[i];
        with_ver[j] = false;
    }
    DSU dsu(n);
    vector<int> point;
    int con = n;
    for (int i = 0; i < n; i ++) {
        if (with_ver[i]) con -= dsu.merge(i, ver);
        else point.push_back(i);
    }
    vector<bool> to(n);
    for (auto x : point) {
        mem(st, 0);
        // st为0表示可以连通
        for (int i = h[x]; ~i; i = ne[i]) {
            int j = e[i];
            st[j] = 1;
        }
        for (int i = 0; i < n; i ++) {
            if (!st[i]) {
                con -= dsu.merge(i, x);
            }
        }
    }
    
    vector<vector<int>> res(con);
    vector<int> id(n, -1);
    idx = 0;
    for (int i = 0; i < n; i ++) {
        if (dsu.leader(i) == i) {
            id[i] = idx ++;
        }
    }
    
    for (int i = 0; i < n; i ++) {
        int root = id[dsu.leader(i)];
        res[root].push_back(i + 1);
    }
    cout << con << endl;
    for (auto& vec : res) {
        cout << sz(vec) << ' ' << vec << endl;
    }
}