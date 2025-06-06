void solve(){
    auto W = [&](i64 x)->i64{
        return (x+1)*x/2;
    };

    i64 n, x, y, c;
    cin >> n >> x >> y >> c;
    auto chk = [&](i64 mid)->bool{
        i64 all = 2*mid*mid + 2*mid + 1;

        i64 rare = 0;
        if (mid > x-1){  // 分别考虑上、下、左、右
            i64 u = mid - (x-1);
            rare += u*u;
        }
        if (mid > n-x){
            i64 u = mid - (n-x);
            rare += u*u;
        }
        if (mid > y-1){
            i64 u = mid - (y-1);
            rare += u*u;
        }
        if (mid > n-y){
            i64 u = mid - (n-y);
            rare += u*u;
        }

        i64 r = mid - (n-y), l = mid - (y-1);  // 分别考虑右上、右下、左上、左下
        if (r > x) rare -= W(r-x);
        if (r > n-x+1) rare -= W(r - (n-x+1));
        if (l > x) rare -= W(l-x);
        if (l > n-x+1) rare -= W(l - (n-x+1));

        return all-rare >= c;
    };

    i64 lo = 0, hi = 2*n;
    while (lo < hi){
        i64 mid = (lo+hi) >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << "\n";
}
