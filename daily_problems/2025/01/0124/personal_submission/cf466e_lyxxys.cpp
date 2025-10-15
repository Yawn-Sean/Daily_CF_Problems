// merge on segment tree
struct Node {
    int l, r;
};
const int N = 1e5+11, inf = 1e9;
const int limi = 1e5;
vector <Node> info(N*30);
struct Tree {
    int tot;
    vector <int> bin;
    Tree(){
        tot = -1;
        open();
    }  
    int open(){
        if (!bin.empty()){
            int x = bin.back();
            bin.pop_back();
            info[x] = {0, 0};
            return x;
        } else {
            ++ tot;
            info[tot] = {0, 0};
            return tot;
        }
    }
    void set(int &u, int loc, int v, int pl, int pr){
        if (!u) u = open();
        if (pl == pr){
            if (v == inf) u = 0;
            return;
        }
        int mid = (pl + pr) >> 1;
        if (loc <= mid){
            set(info[u].l, loc, v, pl, mid);
        } else {
            set(info[u].r, loc, v, mid+1, pr);
        }

        if (!info[u].l && !info[u].r){
            bin.push_back(u);
            u = 0;
        }
    }
    int merge(int x, int y, int lt, int rt){
        if (!x || !y) return x+y;
        int mid = (lt+rt) >> 1;
        info[x].l = merge(info[x].l, info[y].l, lt, mid);
        info[x].r = merge(info[x].r, info[y].r, mid+1, rt);
        return x;
    }
    int query(int u, int loc, int lt, int rt){
        if (!u) return 0;
        if (lt == rt) return 1;
        int mid = (lt+rt) >> 1;
        if (loc <= mid) return query(info[u].l, loc, lt, mid);
        else return query(info[u].r, loc, mid+1, rt);
    }
    void set(int &u, int loc, int v){
        set(u, loc, v, 1, limi);
    }
    int query(int u, int loc){
        return query(u, loc, 1, limi);
    }
    int merge(int x, int y){
        return merge(x, y, 1, limi);
    }
};

void solve(){
    using Yint = Tree;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1), dels(n+1), qrys(n+1);
    vector <int> p(n+1), asks;
    iota(p.begin(), p.end(), 0);
    auto find = [&](auto &&self, int x)->int{
        return p[x] = p[x]==x ? x : self(self, p[x]);
    };
    auto merge = [&](int x, int y)->void{
        x = find(find, x), y = find(find, y);
        if (x == y) return;
        p[x] = y;
    };

    vector <int> roots(n+1);
    Yint Y;
    int tot = 0, ask_len = 0;
    for (int i = 0, type,x,y; i < m; ++ i){
        cin >> type;
        if (type == 1){
            cin >> x >> y;
            merge(x, y), g[y].push_back(x);
        } else if (type == 2) {
            cin >> x;
            ++ tot;
            Y.set(roots[x], tot, 1);
            int j = find(find, x);
            dels[j].push_back(tot);
        } else {
            cin >> x >> y;
            asks.push_back(y);
            qrys[x].push_back(ask_len++);
        }
    }

    vector <int> ans(ask_len);

    auto dfs_merge = [&](auto &&self, int u)->void{
        for (auto &v : g[u]){
            self(self, v);
            roots[u] = Y.merge(roots[u], roots[v]);
        }

        for (auto &id : qrys[u]){
            int x = asks[id];
            ans[id] = Y.query(roots[u], x);
        }
        for (auto &x : dels[u]){
            Y.set(roots[u], x, inf);
        }
    };
    for (int i = 1; i <= n; ++ i){
        if (find(find, i) == i){
            dfs_merge(dfs_merge, i);
        }
    }

    for (auto &x : ans){
        if (x == 0){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
