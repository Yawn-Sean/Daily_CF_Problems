void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector <i64> spends(n), times(n), epis(m), pr(n), f(n);
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    for (auto &x : spends){
        cin >> x;
    }
    for (auto &x : times){
        cin >> x;
    }
    for (auto &x : epis){
        cin >> x;
    }
    sort(p.begin(), p.end(), [&](int &u, int &v){
        return times[u] < times[v];
    });

    for (int i = 0; i < n; ++ i){
        int u = p[i];
        pr[i] = spends[u];
        if (i) pr[i] += pr[i-1];
        f[i] = times[u] - pr[i];
    }
    for (int i = n-2; i >= 0; -- i){
        fmin(f[i], f[i+1]);
    }
    for (int i = 1; i < m; ++ i){
        epis[i] += epis[i-1];
    }

    sort(times.begin(), times.end());
    vector <int> res;

    while (q--){
        i64 x;
        cin >> x;
        int j = lower_bound(times.begin(), times.end(), x) - times.begin();
        i64 v = x;
        if (j < n) fmin(v, f[j]);
        if (j) fmin(v, x - pr[j-1]);
        res.push_back(upper_bound(epis.begin(), epis.end(), v)-epis.begin());
    }
    print(res);
}
