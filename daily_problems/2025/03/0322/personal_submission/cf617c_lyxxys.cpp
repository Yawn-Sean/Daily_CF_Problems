void solve(){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector <i64> xs = {x1}, ys = {y1};
    for (int i = 0,x,y; i < n; ++ i){
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    vector <int> idx(n+1);
    iota(idx.begin(), idx.end(), 0);
    auto W1 = [&](int i)->i64{
        return (xs[i]-x1)*(xs[i]-x1) + (ys[i]-y1)*(ys[i]-y1);
    };
    auto W2 = [&](int i)->i64{
        return (xs[i]-x2)*(xs[i]-x2) + (ys[i]-y2)*(ys[i]-y2);
    };
    sort(idx.begin(), idx.end(), [&](int &u, int &v){
        return W1(u) < W1(v);
    });

    i64 res = inf_i64;
    for (int i = 0; i < n+1; ++ i){
        vector <int> vis(n+1);
        for (int j = 0; j <= i; ++ j){
            vis[idx[j]] = 1;
        }
        i64 r1 = W1(idx[i]), r2 = 0;
        for (int j = 0; j < n+1; ++ j){
            if (!vis[j]){
                fmax(r2, W2(j));
            }
        }
        fmin(res, r1+r2);
    }

    cout << res << "\n";
}
