const int N = 3e5 + 5;

int T, n, m, k, x[N], y[N], cntx[N], cnty[N];
vector<tuple<int, int>> xs, ys;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> m >> k;
        rep(i, 1, n) cin >> x[i];
        rep(i, 1, m) cin >> y[i];
        rep(i, 1, k) {
            int px, py;
            cin >> px >> py;
            bool fx = binary_search(x + 1, x + 1 + n, px);
            bool fy = binary_search(y + 1, y + 1 + m, py);
            if(fx && fy) continue;
            else if(fx) {
                int pos = lower_bound(y + 1, y + 1 + m, py) - y;
                ++cnty[pos];
                xs.emplace_back(px, pos);
            }
            else {
                int pos = lower_bound(x + 1, x + 1 + n, px) - x;
                ++cntx[pos];
                ys.emplace_back(py, pos);
            }
        }
        ll ans = 0;
        rep(i, 1, n) ans += 1LL * cntx[i] * (cntx[i] - 1) / 2;
        rep(i, 1, m) ans += 1LL * cnty[i] * (cnty[i] - 1) / 2;
        sort(xs.begin(), xs.end());
        for(int l = 0, r; l < xs.size(); l = r) {
            for(r = l; r < xs.size() && xs[l] == xs[r]; ++r);
            ans -= 1LL * (r - l) * (r - l - 1) / 2;
        }
        sort(ys.begin(), ys.end());
        for(int l = 0, r; l < ys.size(); l = r) {
            for(r = l; r < ys.size() && ys[l] == ys[r]; ++r);
            ans -= 1LL * (r - l) * (r - l - 1) / 2;
        }
        cout << ans << endl;
        rep(i, 1, n) cntx[i] = 0;
        rep(i, 1, m) cnty[i] = 0;
        xs.clear();
        ys.clear();
    }
    return 0;
}
