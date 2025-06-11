// https://codeforces.com/contest/1292/submission/265695993
/*
  爆long long, 用高精度
*/
void sol_new()
{
    LL _x0, _y0, _ax, _ay, _bx, _by, _xs, _ys, _t;
    cin >> _x0 >> _y0 >> _ax >> _ay >> _bx >> _by;
    cin >> _xs >> _ys >> _t;
    LL u = _ys + _t, d = _ys - _t, r = _xs + _t, l = _xs - _t;
    vector<pair<vector<int>, vector<int>>> vec;
    vector<int> x0 = std::move(ini(_x0));
    vector<int> y0 = std::move(ini(_y0));
    vector<int> ax = std::move(ini(_ax));
    vector<int> ay = std::move(ini(_ay));
    vector<int> bx = std::move(ini(_bx));
    vector<int> by = std::move(ini(_by));
    vector<int> xs = std::move(ini(_xs));
    vector<int> ys = std::move(ini(_ys));
    vector<int> t = std::move(ini(_t));
    vector<int> xt = x0, yt = y0, right = std::move(ini(r)), up = std::move(ini(u));
    while (!comp(xt, right) || !comp(yt, up)) {
        vec.push_back({xt, yt});
        auto px = mul(ax, xt), py = mul(ay, yt);
        xt = add(px, bx), yt = add(py, by);
    }
    vec.push_back({xt, yt});
    int res = 0;
    vector<int> back(t.begin(), t.end());
    for (int i = vec.size() - 1; i >= 0; i--) {
        xt = xs, yt = ys;
        int tmp = 0;
        t = back;
        int j = i;
        while (j < vec.size()) {
            auto &[x, y] = vec[j];
            vector<int> dx = sub(xt, x), dy = sub(yt, y);
            vector<int> dis = add(dx, dy);
            if (comp(t, dis)) {
                t = sub(t, dis);
                // show(t);
                xt = x, yt = y;
                tmp++;
            } else break;
            if (j > 0 && j <= i) j--;
            else if (j == 0) j = i + 1;
            else j++;
        }
        res = max(res, tmp);
    }
    cout << res << '\n';
}
