void solve(){
    
    auto normal = [&](int y, int x)->array<int,2>{
        if (y == 0) return {0, 1};
        if (x == 0) return {1, 0};

        int d = __gcd(x, y);
        x /= d, y /= d;
        if (x < 0){
            x = -x, y = -y;
        }
        return {y, x};
    };
    auto C2 = [&](int x)->int{
        return x * (x-1) / 2;
    };

    int n;
    cin >> n;
    vector <array<int,2>> p(n);
    for (auto &i : p){
        cin >> i[0] >> i[1];
    }

    i64 res = 0;
    for (int i = 2; i < n; ++ i){
        map <array<int,2>, int> mps;

        for (int j = 0; j < i; ++ j){
            auto v = normal(p[i][1]-p[j][1], p[i][0]-p[j][0]);
            mps[ normal(p[i][1]-p[j][1], p[i][0]-p[j][0]) ] += 1;
        }

        res += C2(i);
        for (auto &it : mps){
            int v = it.second;
            if (v > 1){
                res -= C2(v);
            }
        }
    }

    cout << res << "\n";
}
