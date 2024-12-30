const int N = 1.5e5 + 5, inf = 0x3f3f3f3f;

int n;
vector<tuple<int, int>> xl, yl, xr, yr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        xl.emplace_back(a, i);
        yl.emplace_back(b, i);
        xr.emplace_back(c, i);
        yr.emplace_back(d, i);
    }
    sort(xl.begin(), xl.end(), greater<tuple<int, int>>());
    sort(yl.begin(), yl.end(), greater<tuple<int, int>>());
    sort(xr.begin(), xr.end());
    sort(yr.begin(), yr.end());
    rep(i, 1, n) {
        int xln = i == get<1>(xl[0]) ? get<0>(xl[1]) : get<0>(xl[0]);
        int yln = i == get<1>(yl[0]) ? get<0>(yl[1]) : get<0>(yl[0]);
        int xrn = i == get<1>(xr[0]) ? get<0>(xr[1]) : get<0>(xr[0]);
        int yrn = i == get<1>(yr[0]) ? get<0>(yr[1]) : get<0>(yr[0]);
        if(xln <= xrn && yln <= yrn) return (cout << xln << " " << yln << endl), 0;
    }
    return 0;
}
