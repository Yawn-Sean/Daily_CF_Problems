void solve(){
    using ary2 = array<int,2>;
    int n, m, tar, t;
    cin >> n >> m >> tar >> t;
    vector <ary2> cars(n), A;
    for (auto &it : cars){
        cin >> it[0] >> it[1];
    }
    sort(cars.begin(), cars.end(), [&](auto &u, auto &v){
        return u[0]==v[0] ? u[1] > v[1] : u[0] < v[0];
    });
    for (int i = 0, ma = -1; i < n; ++ i){
        if (cars[i][1] > ma){
            A.push_back(cars[i]);
            ma = cars[i][1];
        }
    }

    vector <int> gs(m), ds;
    for (auto &x : gs){
        cin >> x;
    }
    sort(gs.begin(), gs.end());
    ds.push_back(gs[0]);
    for (int i = 1; i < gs.size(); ++ i){
        ds.push_back(gs[i]-gs[i-1]);
    }
    ds.push_back(tar-gs.back());

    auto chk = [&](int mid)->bool{
        i64 cur = 0;
        int vol = A[mid][1];
        for (auto &d : ds){
            if (vol-d < 0) return false;
            i64 y = min(d, vol-d), x = d-y;
            cur += 2*x+y;

            assert(x+y == d);
            if (cur > t) return false;
        }
        return true;
    };
    int lo = 0, hi = A.size()-1;
    while (lo < hi){
        int mid = (lo+hi) >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }

    if (!chk(lo)) cout << -1 << "\n";
    else cout << A[lo][0] << "\n";
}
