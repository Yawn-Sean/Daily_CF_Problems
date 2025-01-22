void solve(){
    int n;
    cin >> n;
    vector <int> ls(n), rs(n);
    for (int i = 0; i < n; ++ i){
        cin >> ls[i] >> rs[i];
    }

    auto call = [&](int k)->int{
        int len = 1 << k;
        int all = 0;
        vector <array<int,2>> difs = {{0,0}};
        for (int i = 0; i < n; ++ i){
            int l = ls[i], r = rs[i];
            if (r-l+1 >= len) all += 1;
            else {
                l %= len, r %= len;
                if (l <= r){
                    difs.push_back({l, 1});
                    difs.push_back({r+1, -1});
                } else {
                    swap(l, r);
                    difs[0][1] += 1;
                    difs.push_back({r, 1});
                    difs.push_back({l+1, -1});
                }
            }
        }
        sort(difs.begin(), difs.end(), [&](auto &u, auto &v){
            return u[0] == v[0] ? u[1] < v[1] : u[0] < v[0];
        });

        int cur = 0, res = 0;
        for (int i = 0; i < difs.size(); ++ i){
            if (difs[i][0] == len) break;
            cur += difs[i][1];
            fmax(res, cur+all);
        }

        return res;
    };

    vector <int> ans(30);
    for (int i = 0; i < 30; ++ i){
        ans[i] = call(i);
    }

    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        cout << ans[__builtin_ctz(x)] << "\n";
    }
}
