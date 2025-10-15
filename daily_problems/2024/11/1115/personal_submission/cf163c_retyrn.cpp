int n, v1, v2;
ll l;

void solve() {
    cin >> n >> l >> v1 >> v2;
    vector<ll> a(n);
    cin >> a;
    
    ll up = l * v2;
    l *= (v1 + v2);
    map<ll, int> diff;
    
    auto add = [&](ll x, ll y) {
        diff[x] ++;
        diff[y] --;
    };

    for (auto x : a) {
        x *= (v1 + v2);
        if (x + up <= l + l) {
            add(x, x + up);
        }
        else {
            add(0, x + up - l * 2);
            add(x, l * 2);
        }
    }
    
    if (!diff.count(l * 2)) diff[l * 2] = 0;
    
    vector<ll> res(n + 1);
    
    ll last = 0;
    int cur = 0;
    
    for (auto& [k, v] : diff) {
        res[cur] += k - last;
        cur += v;
        last = k;
    }
    for (auto x : res) {
        cout << (long double)x / (l + l) << endl;
    }
}
