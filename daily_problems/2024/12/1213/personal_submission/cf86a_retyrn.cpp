ll l, r;

int get(ll x) {
    int ans = 0;
    while (x > 0) {
        ans += 1;
        x /= 10;
    }
    return ans;
}

ll power(int u, int len) {
    ll res = 1;
    while (len > 0) {
        res *= u;
        len --;
    }
    return res;
}

void solve() {
    cin >> l >> r;
    
    int len = get(r);
    ll t = power(10, len) - 1;
    ll down = (t + 1) / 10;
    if (l < down) l = down;
    
    ll mid = t >> 1;
    ll res = max(l * (t - l), r * (t - r));
    
    if (l <= mid and mid <= r) {
        chmax(res, mid * (t - mid));
    }
    if (l <= mid + 1 and mid + 1 <= r) {
        chmax(res, (mid + 1) * (t - mid - 1));
    }
    cout << res << endl;
}