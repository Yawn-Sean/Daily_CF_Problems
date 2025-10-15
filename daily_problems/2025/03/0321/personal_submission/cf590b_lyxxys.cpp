void solve(){
    int x1, y1, x2, y2, vx, vy, wx, wy, vma;
    f64 t;
    cin >> x1 >> y1 >> x2 >> y2 >> vma >> t >> vx >> vy >> wx >> wy;

    x2 -= x1, y2 -= y1;
    f64 lo = 0, hi = 1e9;

    for (int i = 0; i < 200; i ++) {
        f64 mid = (lo+hi) / 2;
        f64 x = x2, y = y2;
        x -= min(mid, t) * vx;
        y -= min(mid, t) * vy;
        x -= (mid - min(mid, t)) * wx;
        y -= (mid - min(mid, t)) * wy;

        if (x*x+y*y <= vma*vma*mid*mid){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(20) << (lo+hi) / 2;

}
