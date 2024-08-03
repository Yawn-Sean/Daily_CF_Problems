

int cal(vector<PII> &v, int mx) {
    int m = SZ(v);
    auto t = new BIT(N);
    sort(all(v));
    int ans = 0;
    for (int i = 0; i < m; i ++ ) {
        int res = t->query(mx - v[i].x);
        if (res > 0) ans = max(ans, v[i].y + res);
        t->add(v[i].x, v[i].y);
    }
    return ans;
}

void solve(int _) 
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<PII> a, b;
    int mxa = 0, mxb = 0;
    for (int i = 0; i < n; i ++ ) {
        int x, p;
        char type;
        cin >> x >> p >> type;
        if (type == 'C') {
            if (p <= c) {
                
                a.emplace_back(p, x);
                mxa = max(mxa, x);
            }
        } else {
            if (p <= d) {
                b.emplace_back(p, x);
                mxb = max(mxb, x);
            }
        }
    }
    int ans = 0;
    if (mxa != 0 && mxb != 0) ans = mxa + mxb;

    ans = max(ans, cal(a, c));
    ans = max(ans, cal(b, d));

    cout << ans << endl;

} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}