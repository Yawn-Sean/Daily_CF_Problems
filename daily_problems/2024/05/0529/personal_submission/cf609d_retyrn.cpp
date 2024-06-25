using pli = pair<ll, int>;
int n, m, k, s;

void solve() {
    cin >> n >> m >> k >> s;
    vector<pii> d(n), e(n);
    for (int i = 0; i < n; i ++) {
        cin >> d[i].fi;
        d[i].se = i;
        
        if (i and d[i].fi > d[i-1].fi) {
            d[i].fi = d[i-1].fi;
            d[i].se = d[i-1].se;
        }
    }
    for (int i = 0; i < n; i ++) {
        cin >> e[i].fi;
        e[i].se = i;
        
        if (i and e[i].fi > e[i-1].fi) {
            e[i].fi = e[i-1].fi;
            e[i].se = e[i-1].se;
        }
    }
      
    vector<pii> a(m);
    cin >> a;
    
    auto check = [&](int len) {
        int md = d[len - 1].fi, me = e[len - 1].fi;
        // 去买前k小的东西
        priority_queue<ll> q;
        for (int i = 0; i < m; i ++) {
            ll t = (ll)a[i].se * (a[i].fi == 1 ? md : me);
            q.push(t);
            while (sz(q) > k) q.pop();
        }
        
        ll need = 0;
        while (!em(q)) {
            need += q.top();
            q.pop();
        }
        return need <= s;
    };
    
    if (!check(n)) {
        cout << -1 << endl;
        return;
    }
    
    int l = 1, r = n;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    
    priority_queue<pli> q;
    for (int i = 0; i < m; i ++) {
        ll t = (ll)a[i].se * (a[i].fi == 1 ? d[l-1].fi : e[l-1].fi);
        q.emplace(t, i); 
        while (sz(q) > k) q.pop();
    }
    
    while (!em(q)) {
        auto [cost, id] = q.top();
        q.pop();
        cout << id + 1 << ' ' << (a[id].fi == 1 ? d[l-1].se + 1 : e[l-1].se + 1) << endl;
    }
}