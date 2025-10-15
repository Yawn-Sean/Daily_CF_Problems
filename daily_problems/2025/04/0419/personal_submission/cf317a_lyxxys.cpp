void solve(){
    i64 x, y, m;

    cin >> x >> y >> m;

    if (x >= m || y >= m){
        cout << 0 << "\n";
    } else if (x <= 0 && y <= 0){
        cout << -1 << "\n";
    } else {
        if (x > y) swap(x, y);

        i64 res = 0;

        if (x < 0){
            i64 k = (-x + y - 1) / y;
            x += k * y;
            res += k;
        }

        while (x < m && y < m){
            i64 u = x+y;
            if (x < y){
                x = u;
            } else {
                y = u;
            }
            res += 1;
        }

        cout << res << "\n";
    }

}
