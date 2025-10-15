void solve(){
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    map <i64,array<int,3>> mps;
    set <array<int,2>> st;

    queue <array<int,3>> Q;
    Q.push({a1, b1, 0});
    
    while (!Q.empty()){
        auto [x, y, dis] = Q.front();
        Q.pop();

        if (x > y) swap(x, y);
        if (st.count({x, y})) continue;

        st.insert({x, y});
        mps[1ll*x*y] = {x, y, dis};

        if (x%2 == 0){
            Q.push({x/2, y, dis+1});
        }
        if (x%3 == 0){
            Q.push({x-x/3, y, dis+1});
        }
        if (y%2 == 0){
            Q.push({x, y/2, dis+1});
        }
        if (y%3 == 0){
            Q.push({x, y-y/3, dis+1});
        }
    }

    int res = inf_int;
    array<int,4> ans = {-1,-1,-1,-1};

    Q.push({a2, b2, 0});
    st.clear();

    while (!Q.empty()){
        auto [x, y, dis] = Q.front();
        Q.pop();

        if (x > y) swap(x, y);
        if (st.count({x, y})) continue;
        st.insert({x, y});

        if (mps.count(1ll*x*y)){
            auto [ix, iy, d1] = mps[1ll*x*y];
            if (d1+dis < res){
                res = d1+dis;
                ans = {ix, iy, x, y};
            }
        }

        if (dis > res) continue;

        if (x%2 == 0){
            Q.push({x/2, y, dis+1});
        }
        if (x%3 == 0){
            Q.push({x-x/3, y, dis+1});
        }
        if (y%2 == 0){
            Q.push({x, y/2, dis+1});
        }
        if (y%3 == 0){
            Q.push({x, y-y/3, dis+1});
        }
    }


    if (res == inf_int){
        cout << -1 << "\n";
    } else {
        cout << res << "\n";
        cout << ans[0] << " " << ans[1] << "\n";
        cout << ans[2] << " " << ans[3] << "\n";
    }
}
