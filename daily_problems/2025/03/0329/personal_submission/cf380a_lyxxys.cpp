void solve(){
    const int limi = 1e5+10;

    int m, n;
    cin >> m;
    vector<array<int,2>> types;
    vector <i64> w(m);
    
    vector <int> ori;

    for (int i = 0, type, l, c; i < m; ++ i){
        cin >> type;
        if (type == 1){
            cin >> l;
            types.push_back({l, -1});
            w[i] = 1;
            ori.push_back(l);
        } else {
            cin >> l >> c;
            types.push_back({l, c});
            w[i] = l*c;

            for (int i1 = 0; i1 < c && ori.size() < limi; ++ i1){
                for (int i2 = 0; i2 < l && ori.size() < limi; ++ i2){
                    int x = ori[i2];
                    ori.push_back(x);
                }
            }
        }
        if (i > 0) w[i] += w[i-1];
    }


    cin >> n;
    vector <i64> A(n), ans;
    for (auto &x : A){
        cin >> x;
    }

    for (int i = 0, j = -1; i < n; ++ i){
        i64 x = A[i];
        while (j+1 < m && x > w[j+1]){
            j += 1;
        }
        assert(j+1 < m);

        i64 d = x - (j==-1 ? 0 : w[j]);
        if (types[j+1][1] == -1){
            assert(d == 1);
            ans.push_back(types[j+1][0]);
        } else {
            int l = types[j+1][0], c = types[j+1][1];
            d -= 1;
            d %= l;
            ans.push_back(ori[d]);
        }
    }

    print(ans);
}
