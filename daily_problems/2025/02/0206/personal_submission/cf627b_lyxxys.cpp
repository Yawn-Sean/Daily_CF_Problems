struct segTree {
    vector <int> info;
    int n, k;
    segTree(){}
    segTree(int n, int k): info(4*n+1), n(n), k(k) {}
    void pull(int u){
        info[u] = info[u*2] + info[u*2+1];
    }
    void update(int u, int loc, i64 val, int lt, int rt){
        if (lt == rt){
            info[u] += val;
            info[u] = min(info[u], k);
            return;
        }
        int mid = (lt + rt) >> 1;
        if (loc <= mid) update(u*2, loc, val, lt, mid);
        else update(u*2+1, loc, val, mid+1, rt);
        pull(u);
    }
    void update(int loc, i64 val){
        update(1, loc, val, 1, n);
    }
    int query(int u, int l, int r, int lt, int rt){
        if (lt >= l && rt <= r) return info[u];
        int res = 0;
        int mid = (lt + rt) >> 1;
        if (mid >= l) res += query(u*2, l, r, lt, mid);
        if (mid < r) res += query(u*2+1, l, r, mid+1, rt);
        return res;
    }
    int query(int l, int r){
        if (l > r) return 0;
        int res = query(1, l, r, 1, n);
        return res;
    }
};

void solve(){
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    
    segTree Y1(n, b), Y2(n, a);
    for (int i = 0, type, day, d; i < q; ++ i){
        cin >> type >> day;
        if (type == 1){
            cin >> d;
            Y1.update(day, d), Y2.update(day, d);
        } else {
            int res = Y1.query(1, day-1)+Y2.query(day+k, n);
            cout << res << "\n";
        }
    }
}
