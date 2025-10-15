void solve(){
    cout << fixed << setprecision(15);
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int D = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    if (D > (r1+r2)*(r1+r2)){
        f64 d = sqrtl(D)-(r1+r2);
        cout << d/2 << "\n";
    } else if (D < (r1-r2)*(r1-r2)){
        f64 d = max(r1, r2) - (sqrtl(D)+min(r1,r2));
        cout << d/2 << "\n";
    } else {
        cout << (f64)0 << "\n";
    }
}
