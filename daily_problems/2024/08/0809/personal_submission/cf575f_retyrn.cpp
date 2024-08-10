int n, x;

void solve() {
    cin >> n >> x;
    int l = x, r = x;
    ll res = 0;
    
    while (n --) {
        int a, b;
        cin >> a >> b;
        if (r < a) {
            res += a - r;
            l = r, r = a;
        }
        else if (l > b) {
            res += l - b;
            r = l, l = b;
        }
        else {
            l = max(l, a), r = min(r, b);
        }
    }
    cout << res << endl;
}