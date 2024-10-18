int h, q;
using pll = pair<ll, ll>;

void merge(vector<pll> &segs) {
    vector<pll> res;
    sort(segs.begin(), segs.end());
    ll st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

void get(ll& a, ll& b, int layer) {
    while (layer < h) {
        layer ++;
        a <<= 1;
        b = (b << 1) | 1;
    }
}
void solve() {
    cin >> h >> q;
    
    ll l = (1LL << (h - 1)), r = (1LL << h) - 1;
    vector<pll> ban;
    
    while (q --) {
        int layer, ans;
        ll a, b;
        cin >> layer >> a >> b >> ans;
        get(a, b, layer);
        
        if (ans) {
            l = max(l, a);
            r = min(r, b);
        }
        else {
            ban.emplace_back(a, b);
        }
        if (l > r) {
            cout << "Game cheated!" << endl;
            return;
        }
    }
    
    merge(ban);
    
    if (em(ban)) {
        if (l == r) {
            cout << l << endl;
            return;
        }
        cout << "Data not sufficient!" << endl;
        return;
    }
    
    vector<ll> res;
    
    for (int i = 0; i + 1 < sz(ban); i ++) {
        ll st = max(l, ban[i].se + 1), ed = min(r, ban[i + 1].fi - 1);
        for (ll j = st; j <= ed and sz(res) <= 1; j ++) {
            res.push_back(j);
        }
    }
    ll st = max(l, (1LL << (h - 1))), ed = min(r, ban[0].fi - 1);
    for (ll j = st; j <= ed and sz(res) <= 1; j ++) {
        res.push_back(j);
    }
    st = max(l, ban.back().se + 1), ed = min(r, (1LL << h) - 1);
    for (ll j = st; j <= ed and sz(res) <= 1; j ++) {
        res.push_back(j);
    }
    
    if (sz(res) == 1) {
        cout << res[0] << endl;
    }
    else {
        cout << (sz(res) == 0 ? "Game cheated!" : "Data not sufficient!") << endl;
    }
}