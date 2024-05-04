int n, tmp;

void solve() {
    cin >> n >> tmp;
    vector<int> a(n), t(n);
    cin >> a;
    for (int i = 0; i < n; i ++) {
        cin >> t[i];
        t[i] -= tmp;
    }
    // 0的水全部拿下
    ll sum = 0, cnt = 0;
    double res = -1;
    priority_queue<pii, vector<pii>, greater<pii>> cold;
    priority_queue<pii> hot;
    for (int i = 0; i < n; i ++) {
        if (t[i] == 0) cnt += a[i];
        else if (t[i] > 0) {
            hot.emplace(t[i], a[i]);
            cnt += a[i];
            sum += (ll)a[i] * t[i];
        }
        else {
            cold.emplace(t[i], a[i]);
            cnt += a[i];
            sum += (ll)a[i] * t[i];
        }
    }
    
    while (sum > 0) {
        // 从热水中扣
        auto [x, cap] = hot.top();
        hot.pop();
        if ((ll)x * cap <= sum) {
            sum -= (ll)x * cap;
            cnt -= cap;
            continue;
        }
        res = cnt - (double)sum / x;
        sum = 0;
        break;
    }
    
    while (sum < 0) {
        // 从冷水中扣
        auto [x, cap] = cold.top();
        cold.pop();
        if ((ll)x * cap >= sum) {
            sum -= (ll)x * cap;
            cnt -= cap;
            continue;
        }
        res = cnt - (double)sum / x;
        sum = 0;
        break;
    }
    
    if (res < 0) res = cnt;
    cout << res << endl;
}