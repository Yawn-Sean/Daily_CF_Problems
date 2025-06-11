int n;

void solve() {
    vector<ll> a(3);
    cin >> a;
    sort(all(a));

    if ((a[1] - a[0]) % 2 == 0) cout << a[1] << endl;
    else cout << a[2] << endl;
}