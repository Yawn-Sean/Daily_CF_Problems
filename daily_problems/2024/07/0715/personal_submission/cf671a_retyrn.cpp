using pdi = pair<double, int>;
int n;

double dis(const pii& a, const pii& b) {
    double s = (double)(a.fi - b.fi) * (a.fi - b.fi) + (double)(a.se - b.se) * (a.se - b.se);
    return sqrt(s);
}
void solve() {
    pii A, B, S;
    cin >> A >> B >> S;
    cin >> n;
    vector<pii> a(n);
    cin >> a;
    
    double sum = 0.0;
    for (const auto& p : a) {
        sum += dis(p, S) * 2;
    }
    
    vector<pdi> vA, vB;
    for (int i = 0; i < n; i ++) {
        double d = dis(a[i], A) - dis(a[i], S);
        vA.emplace_back(d, i);
        d = dis(a[i], B) - dis(a[i], S);
        vB.emplace_back(d, i);
    }
    
    sort(all(vA));
    sort(all(vB));
    
    if (n == 1 or (vA[0].fi >= 0 or vB[0].fi >= 0)) {
        auto res = sum + min(vA[0].fi, vB[0].fi);
        cout << res << endl;
        return;
    }
    if (vA[0].se != vB[0].se) {
        auto res = sum + vA[0].fi + vB[0].fi;
        cout << res << endl;
        return;
    }

    auto res = sum + min(vA[0].fi + min(0.0, vB[1].fi), min(0.0, vA[1].fi) + vB[0].fi);
    cout << res << endl;
}