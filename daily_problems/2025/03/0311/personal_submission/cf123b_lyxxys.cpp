void solve(){
    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    auto w1 = [&](int x)->int{
        return (int)floor(1.0*x/(2*a));
    };
    auto w2 = [&](int x)->int{
        return (int)floor(1.0*x/(2*b));
    };

    int res = max(abs(w1(x1+y1)-w1(x2+y2)), abs(w2(y1-x1)-w2(y2-x2)));

    cout << res << "\n";
}
