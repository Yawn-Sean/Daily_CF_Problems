void solve(){
    int tar, m, n;
    cin >> tar >> m >> n;
    vector <int> xs, ps, next(n+1), ids(n+2);
    for (int i = 0,x,p; i < n; ++ i){
        cin >> x >> p;
        xs.push_back(x);
        ps.push_back(p);
    }
    xs.push_back(0), ps.push_back(0);
    xs.push_back(tar), ps.push_back(0);

    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](auto &u, auto &v){
        return xs[u] < xs[v];
    });

    vector <int> stk = {n+1};

    for (int i = n; i >= 0; -- i){
        while (!stk.empty() && ps[ids[i]] < ps[ids[stk.back()]]){
            stk.pop_back();
        }
        next[i] = stk.back();
        stk.push_back(i);
    }

    i64 res = 0, cur = m;
    for (int id = 0; id <= n; ++ id){
        int i = ids[id], j = ids[id+1], nxt = ids[next[id]];
        i64 vol = min(xs[nxt]-xs[i], m) - cur;
        if (vol < 0) vol = 0;
        res += vol * ps[i];
        cur += vol, cur -= xs[j]-xs[i];

        if (cur < 0){
            cout << -1 << "\n";
            return;
        }
    }

    cout << res << "\n";
}
