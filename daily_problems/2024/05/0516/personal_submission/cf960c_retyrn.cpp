ll n;
int d;

void solve() {
    cin >> n >> d;
    vector<ll> res;
    // 每一段是(2^m - 1)个 剩下补1
    ll st = 1;
    while (n > 0LL) {
        // 寻找最大的长度
        int l = 1, r = 30;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            ll sum = (1ll << mid) - 1;
            if (sum > n) r = mid - 1;
            else l = mid;
        }
        for (int i = 0; i < l; i ++) {
            res.push_back(st);
        }
        n -= (1ll << l) - 1;
        st += d;
    }
    cout << sz(res) << endl;
    cout << res << endl;
}