int n, m;

ll get(int len) {
    return (ll)(len + 1) * len / 2;
}

void solve() {
    cin >> n >> m;
    ll sum = 0;
    
    while (m --) {
        int x, d;
        cin >> x >> d;
        sum += (ll)x * n;
        if (d < 0) {
            sum += get((n - 1) / 2) * d;
            sum += get(n - (n - 1) / 2 - 1) * d;
        }
        else {
            sum += get(n - 1) * d;
        }
    }
    cout << (double)sum / n << endl;
}