const ll mod = 1e9 + 7;
 
void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<pair<ll, ll>> schedule;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        schedule.emplace_back(l, r);
    }
    sort(all(schedule));
    ll tot = 0;
    priority_queue<ll> available;
    priority_queue<ll, vector<ll>, greater<>> inprogress;
    for (int i = 0; i < n; i++) {
        auto [st, ed] = schedule[i];
        while (!inprogress.empty() && inprogress.top() < st) {
            ll t = inprogress.top();
            inprogress.pop();
            ll cost = y * (st - t);
            if (cost < x) available.push(t);
        } 
        if (available.empty()) {
            ll cost = (x + y * (ed - st)) % mod;
            tot = (tot + cost) % mod;
            inprogress.push(ed);
        } else {
            ll t = available.top();
            ll cost = y * (st - t);
            if (cost < x) {
                cost = (y * (ed - t)) % mod;
                tot = (tot + cost) % mod;
                available.pop();
            } else {
                ll cost = (x + y * (ed - st)) % mod;
                tot = (tot + cost) % mod;
            }
            inprogress.push(ed);
        }
    }
    cout << tot << "\n";
}
