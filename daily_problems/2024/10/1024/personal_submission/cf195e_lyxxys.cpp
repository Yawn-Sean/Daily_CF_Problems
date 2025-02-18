const int mod = 1e9+7;
struct Tree {
    vector <ll> info, tag;
    Tree(int n): info(4*n), tag(4*n) {}
    void apply(int u, ll x){
        info[u] += x, tag[u] += x;
    }
    void push(int u){
        apply(u*2, tag[u]), apply(u*2+1, tag[u]);
        tag[u] = 0;
    }
    void update(int u, int l, int r, int lt, int rt, ll x){
        if (lt >= l && rt <= r){
            apply(u, x);
            return;
        }
        if (tag[u]) push(u);
        int mid = (lt+rt) >> 1;
        if (mid >= l) update(u*2, l, r, lt, mid, x);
        if (mid < r) update(u*2+1, l, r, mid+1, rt, x);
    }
    ll ask(int u, int pos, int lt, int rt){
        if (lt == rt) return info[u];
        if (tag[u]) push(u);
        int mid = (lt+rt) >> 1;
        if (mid >= pos) return ask(u*2, pos, lt, mid);
        else return ask(u*2+1, pos, mid+1, rt);
    }
};

void solve(){
    int n;
    cin >> n;
    vector <int> p(n+1);
    vector <vector<int>> g(n+1);
    vector <vector<array<int,2>>> opt(n+1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](auto &&self, int x)->int{
        return p[x] = p[x]==x ? x : self(self, p[x]);
    };
    auto merge = [&](int x, int y)->void{
        x = find(find, x), y = find(find, y);
        if (x == y) return;
        p[y] = x;
    };

    for (int i = 1; i <= n; ++ i){
        int k;
        cin >> k;
        while (k--){
            int u, x;
            cin >> u >> x;
            int p = find(find, u);
            merge(i, p);
            g[i].push_back(p);
            opt[i].push_back({u, x});
        }
    }
    
    int tot = 0;
    vector <int> L(n+1), R(n+1);
    Tree Y(n);
    const int N = n;
    auto dfs = [&](auto &&self, int x)->void{
        L[x] = ++ tot;
        for (auto &y : g[x]){
            self(self, y);
        }
        R[x] = tot;
    };
    for (int i = 1; i <= n; ++ i){
        if (find(find, i) == i){
            dfs(dfs, i);
        }
    }

    auto update_Tree = [&](int x, ll d)->void{
        Y.update(1, L[x], R[x], 1, N, d);
    };

    long long res = 0;
    auto call = [&](auto &&self, int x)->void{
        int len = g[x].size();
        for (int i = 0; i < len; ++ i){
            int y = g[x][i];
            self(self, y);

            auto op = opt[x][i];
            ll d = mo(Y.ask(1, L[op[0]], 1, N) + op[1]);
            res += d;
            res = (res%mod + mod) % mod;
            update_Tree(y, d);
        }
    };

    for (int i = 1; i <= n; ++ i){
        if (find(find, i) == i){
            call(call, i);
        }
    }

    cout << res << "\n";
}

