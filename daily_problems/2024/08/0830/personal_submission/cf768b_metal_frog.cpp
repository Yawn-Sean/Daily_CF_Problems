unordered_map<ll, ll> len, cnt;
ll ans = 0;
 
void calc(ll n) {
    if (len.find(n) != len.end()) {
        return;
    } 
    calc(n / 2);
    len[n] = len[n / 2] * 2LL + 1;
    cnt[n] = cnt[n / 2] * 2LL;
    if (n % 2 == 1) cnt[n]++;
}
 
void query(ll n, ll l, ll r) {
    if (l == 1 && r == len[n]) {
        ans += cnt[n];
        return;
    }
    if (l <= len[n / 2] && r <= len[n / 2]) {
        query(n / 2, l, r);
        return;
    } else if (l > len[n / 2] + 1 && r > len[n / 2] + 1) {
        l -= len[n / 2] + 1;
        r -= len[n / 2] + 1;
        query(n / 2, l, r);
        return;
    } else if (l == len[n / 2] + 1) {
        ans += (n % 2LL == 1);
        if (r == len[n / 2] + 1) return;
        else {
            r -= (len[n / 2] + 1);
            query(n / 2, 1, r);
            return;
        }
    } else if (r == len[n / 2] + 1) {
        ans += (n % 2LL == 1);
        query(n / 2, l, len[n / 2]);
    } else if (l < len[n / 2] + 1 && r > len[n / 2] + 1) {
        ans += (n % 2LL == 1);
        query(n / 2, l, len[n / 2]);
        query(n / 2, 1, r - len[n / 2] - 1);
    }
}
 
void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    len[0] = 1; len[1] = 1; len[2] = 3; len[3] = 3;
    cnt[0] = 0, cnt[1] = 1; cnt[2] = 2, cnt[3] = 3;
    calc(n);
    query(n, l, r);
    cout << ans << "\n";
}
