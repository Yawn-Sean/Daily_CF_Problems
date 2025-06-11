map<ll, ll> mp;

ll cal(ll x) {
    if (x <= 1) return 1;
    if (mp.count(x)) return mp[x];
    auto len = cal(x / 2);
    mp[x] = len * 2 + 1;
    return mp[x];
}

int dfs(ll n, ll l, ll sum) {
    if (sum <= 0) return 0;
    if (n <= 1) {
        if (l == 1 and sum == 1) return n;
        return 0;
    }
    auto len = cal(n / 2);
    if (l > len + 1) return dfs(n / 2, l - len - 1, sum);
    if (l == len + 1) return dfs(n / 2, 1, sum - 1) + n % 2;
    int res = dfs(n / 2, l, min(sum, len - l + 1));
    sum -= min(sum, len - l + 1);
    if (sum > 0) {
        res += n % 2;
        sum -= 1;
    }
    if (sum > 0) {
        res += dfs(n / 2, 1, sum);
        sum = 0;
    }
    return res;
}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    auto res = dfs(n, l, r - l + 1);
    cout << res << endl;
}